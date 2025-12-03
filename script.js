// ---------- Demo data with domains ----------
let profiles = [
  {
    id: 1,
    name: "Asha",
    teachSkill: "C programming",
    teachLevel: "Intermediate",
    teachDomain: "Technology",
    learnSkill: "Guitar",
    learnLevel: "Beginner",
    learnDomain: "Music",
    availability: "Evening"
  },
  {
    id: 2,
    name: "Rahul",
    teachSkill: "Guitar",
    teachLevel: "Expert",
    teachDomain: "Music",
    learnSkill: "Python",
    learnLevel: "Beginner",
    learnDomain: "Technology",
    availability: "Evening"
  },
  {
    id: 3,
    name: "Meera",
    teachSkill: "Python",
    teachLevel: "Intermediate",
    teachDomain: "Technology",
    learnSkill: "Public speaking",
    learnLevel: "Beginner",
    learnDomain: "Career & Soft Skills",
    availability: "Weekend"
  },
  {
    id: 4,
    name: "Arjun",
    teachSkill: "Public speaking",
    teachLevel: "Expert",
    teachDomain: "Career & Soft Skills",
    learnSkill: "C programming",
    learnLevel: "Beginner",
    learnDomain: "Technology",
    availability: "Weekend"
  }
];

let nextId = profiles.length + 1;
let currentUser = null;

// Filters
let filterMutualOnly = false;
let filterMinScore = 40;

// ---------- Helper functions ----------
function normalizeSkill(skill) {
  return skill.trim().toLowerCase();
}

function levelValue(level) {
  const map = {
    Beginner: 1,
    Intermediate: 2,
    Advanced: 3,
    Expert: 3
  };
  return map[level] || 1;
}

/**
 * Analyzes how good a match is between two profiles.
 * Returns { score, mutualSwap, reasons[] }
 */
function analyzeMatch(a, b) {
  let score = 0;
  let reasons = [];

  const aTeach = normalizeSkill(a.teachSkill);
  const aLearn = normalizeSkill(a.learnSkill);
  const bTeach = normalizeSkill(b.teachSkill);
  const bLearn = normalizeSkill(b.learnSkill);

  const mutualSwap = aTeach === bLearn && aLearn === bTeach;
  const oneWayTeachToB = aTeach === bLearn;
  const oneWayBTeachToA = aLearn === bTeach;

  // Mutual skill swap is strongest
  if (mutualSwap) {
    score += 60;
    reasons.push("Mutual skill swap");
  } else {
    if (oneWayTeachToB) {
      score += 30;
      reasons.push(`${a.name} can teach what ${b.name} wants`);
    }
    if (oneWayBTeachToA) {
      score += 30;
      reasons.push(`${b.name} can teach what ${a.name} wants`);
    }
  }

  // Domain alignment boosts score
  if (a.teachDomain === b.learnDomain || a.learnDomain === b.teachDomain) {
    score += 10;
    reasons.push("Aligned domains");
  }

  // Level compatibility: teacher should be >= learner
  if (levelValue(a.teachLevel) >= levelValue(b.learnLevel)) {
    score += 5;
    reasons.push("A has sufficient level to teach");
  }
  if (levelValue(b.teachLevel) >= levelValue(a.learnLevel)) {
    score += 5;
    reasons.push("B has sufficient level to teach");
  }

  // Availability
  if (a.availability === b.availability) {
    score += 10;
    reasons.push("Same availability");
  }

  return { score, mutualSwap, reasons };
}

function findMatches(user) {
  return profiles
    .filter(p => p.id !== user.id)
    .map(p => {
      const analysis = analyzeMatch(user, p);
      return {
        partner: p,
        ...analysis
      };
    })
    .filter(x => x.score > 0)
    .filter(x => !filterMutualOnly || x.mutualSwap)
    .filter(x => x.score >= filterMinScore)
    .sort((a, b) => b.score - a.score);
}

// ---------- UI rendering ----------
const profilesListEl = document.getElementById("profilesList");
const matchesListEl = document.getElementById("matchesList");
const filterMutualEl = document.getElementById("filterMutual");
const minScoreRangeEl = document.getElementById("minScoreRange");
const minScoreLabelEl = document.getElementById("minScoreLabel");

function renderProfiles() {
  profilesListEl.innerHTML = "";
  profiles.forEach(p => {
    const div = document.createElement("div");
    div.className = "card-item";
    div.innerHTML = `
      <div class="card-item-header">
        <div class="card-item-title">${p.name}</div>
        <span class="badge">${p.availability}</span>
      </div>
      <div class="card-item-body">
        <strong>Teaches:</strong> ${p.teachSkill} (${p.teachLevel}, ${p.teachDomain})<br />
        <strong>Wants:</strong> ${p.learnSkill} (${p.learnLevel}, ${p.learnDomain})
      </div>
    `;
    profilesListEl.appendChild(div);
  });
}

function renderMatchesForCurrentUser() {
  if (!currentUser) {
    matchesListEl.innerHTML =
      "<p class='hint'>Submit your profile to see personalized matches.</p>";
    return;
  }
  const matches = findMatches(currentUser);
  renderMatches(matches);
}

function renderMatches(matches) {
  matchesListEl.innerHTML = "";
  if (!matches.length) {
    matchesListEl.innerHTML =
      "<p class='hint'>No matches with current filters. Try lowering the minimum score or unchecking 'Mutual swap only'.</p>";
    return;
  }

  matches.forEach(item => {
    const { partner, score, mutualSwap, reasons } = item;
    const div = document.createElement("div");
    div.className = "card-item";

    const scoreLabel =
      score >= 80 ? "Excellent match" :
      score >= 60 ? "Strong match" :
      score >= 40 ? "Good match" :
      "Basic match";

    const badgeClass = score >= 80 ? "badge badge-strong" : "badge";

    const reasonsHtml = reasons
      .map(r => `<span class="pill">${r}</span>`)
      .join("");

    div.innerHTML = `
      <div class="card-item-header">
        <div class="card-item-title">${partner.name}</div>
        <span class="${badgeClass}">Score: ${score}</span>
      </div>
      <div class="card-item-body">
        <strong>${partner.name}</strong> can teach
        <strong>${partner.teachSkill}</strong> (${partner.teachDomain})
        and wants to learn <strong>${partner.learnSkill}</strong> (${partner.learnDomain}).<br/>
        Availability: <strong>${partner.availability}</strong>
        ${mutualSwap ? "<br/><strong>Mutual swap possible.</strong>" : ""}
        <div class="match-reasons">
          ${reasonsHtml}
        </div>
      </div>
      <div class="card-item-footer">
        <span>${scoreLabel}</span>
        <button class="confirm-btn">Mark as confirmed</button>
      </div>
    `;

    const btn = div.querySelector(".confirm-btn");
    btn.addEventListener("click", () => {
      btn.replaceWith(createConfirmedLabel());
    });

    matchesListEl.appendChild(div);
  });
}

function createConfirmedLabel() {
  const span = document.createElement("span");
  span.className = "confirmed-label";
  span.textContent = "Confirmed";
  return span;
}

// ---------- Form handling ----------
document.getElementById("profileForm").addEventListener("submit", e => {
  e.preventDefault();

  const user = {
    id: nextId++,
    name: document.getElementById("name").value,
    teachSkill: document.getElementById("teachSkill").value,
    teachLevel: document.getElementById("teachLevel").value,
    teachDomain: document.getElementById("teachDomain").value,
    learnSkill: document.getElementById("learnSkill").value,
    learnLevel: document.getElementById("learnLevel").value,
    learnDomain: document.getElementById("learnDomain").value,
    availability: document.getElementById("availability").value
  };

  currentUser = user;
  profiles.push(user);

  // Persist demo data
  try {
    localStorage.setItem("skillSwapProfiles", JSON.stringify(profiles));
  } catch (err) {
    // ignore
  }

  renderProfiles();
  renderMatchesForCurrentUser();
});

// ---------- Filter listeners ----------
filterMutualEl.addEventListener("change", () => {
  filterMutualOnly = filterMutualEl.checked;
  renderMatchesForCurrentUser();
});

minScoreRangeEl.addEventListener("input", () => {
  filterMinScore = Number(minScoreRangeEl.value);
  minScoreLabelEl.textContent = filterMinScore;
  renderMatchesForCurrentUser();
});

// ---------- Init ----------
(function init() {
  try {
    const stored = localStorage.getItem("skillSwapProfiles");
    if (stored) {
      profiles = JSON.parse(stored);
      nextId = profiles.length + 1;
    }
  } catch (err) {
    // ignore
  }
  renderProfiles();
  renderMatchesForCurrentUser();
})();
