1.Experiment
C:\Users\dayan>mkdir heloo

C:\Users\dayan>cd heloo

C:\Users\dayan\heloo>git init
Initialized empty Git repository in C:/Users/dayan/heloo/.git/

C:\Users\dayan\heloo>git config --global user.name

C:\Users\dayan\heloo>git config --global user.name "xxxxxxx77"

C:\Users\dayan\heloo>git config --global user.email  "xxxxxxyy@gmail.com"

C:\Users\dayan\heloo>notepad filegit.txt

C:\Users\dayan\heloo>git add "filegit.txt"

C:\Users\dayan\heloo>git commit -m "added file"
[main (root-commit) ca413d6] added file
 1 file changed, 1 insertion(+)
 create mode 100644 filegit.txt

2.Experiment
C:\Users\dayan\heloo>git checkout -b feature-branch    (-b is used to create a new branch if it exists no need to use -b)
Switched to a new branch 'feature-branch'

C:\Users\dayan\heloo>notepad filegit.txt

C:\Users\dayan\heloo>git add filegit.txt

C:\Users\dayan\heloo>git commit -m "edit"
[feature-branch ea1bcd0] edit
 1 file changed, 2 insertions(+), 1 deletion(-)

C:\Users\dayan\heloo>git checkout main
Switched to branch 'main'

C:\Users\dayan\heloo>git merge feature-branch
Updating ca413d6..ea1bcd0
Fast-forward
 filegit.txt | 3 ++-
 1 file changed, 2 insertions(+), 1 deletion(-)

3.Experiment
C:\Users\dayan\heloo>notepad filegit.txt     (changes med)
C:\Users\dayan\heloo>git stash save "temporary save"
Saved working directory and index state On main: temporary save

C:\Users\dayan\heloo>git checkout feature-branch
Switched to branch 'feature-branch'
C:\Users\dayan\heloo>git stash apply
On branch feature-branch
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   filegit.txt

no changes added to commit (use "git add" and/or "git commit -a")

4.Experiment
C:\Users\Lenovo>git clone https://github.com/gajanaxxxxxxx6-alt/exam.git
Cloning into 'exam'...
remote: Enumerating objects: 5, done.
remote: Counting objects: 100% (5/5), done.
remote: Compressing objects: 100% (5/5), done.
remote: Total 5 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
Receiving objects: 100% (5/5), done.

5.Experiment
C:\Users\dayan\AI_assistant1.5->git fetch origin

C:\Users\dayan\AI_assistant1.5->git rebase origin
dropping 5383f9189b81122628a9c89727b3f48c318af958 Hello world -- patch contents already upstream
Successfully rebased and updated refs/heads/main.

C:\Users\dayan\AI_assistant1.5->git rebase --continue
fatal: no rebase in progress

C:\Users\dayan\AI_assistant1.5->git push origin main
Enumerating objects: 14, done.
Counting objects: 100% (14/14), done.
Delta compression using up to 12 threads
Compressing objects: 100% (12/12), done.
Writing objects: 100% (13/13), 3.12 KiB | 1.56 MiB/s, done.
Total 13 (delta 4), reused 0 (delta 0), pack-reused 0 (from 0)
remote: Resolving deltas: 100% (4/4), done.
To https://github.com/trycode277/AI_assistant1.5-.git
   9c66d1f..e79f9e9  main -> main

6.Experiment
C:\Users\dayan\AI_assistant1.5->git checkout feature-branch(if in origin branch)
Switched to branch 'feature-branch'

C:\Users\dayan\AI_assistant1.5->notepad filegit.txt

C:\Users\dayan\AI_assistant1.5->git add filegit.txt

C:\Users\dayan\AI_assistant1.5->git commit -m "I create new data"
[feature-branch b55ec06] I create new data
 1 file changed, 1 insertion(+)
 create mode 100644 filegit.txt

C:\Users\dayan\AI_assistant1.5->git checkout main
Switched to branch 'main'
Your branch is up to date with 'origin/main'.

C:\Users\dayan\AI_assistant1.5->git merge feature-branch -m “with commit massage”
Merge made by the 'ort' strategy.
 filegit.txt | 1 +
 1 file changed, 1 insertion(+)
 create mode 100644 filegit.txt

7.Experiment
C:\Users\dayan\AI_assistant1.5->git tag v1.0
C:\Users\dayan\AI_assistant1.5->git tag t1.0
C:\Users\dayan\AI_assistant1.5->git tag
t1.0
v1.0
8.Experiment

C:\Users\dayan\AI_assistant1.5->git cherry-pick 3dfce4f
[main 2771c90] add one line 
Date: Tue Dec 9 10:32:56 2025 +0530
 1 file changed, 188 insertions(+)
create mode 100644 Ai_assistent.py

9.Experiment
C:\Users\dayan\AI_assistant1.5->git show bce1123
commit bce11239eccc11052fd1d79e5f28a281e3ce3abb
Merge: f5025d2 d1483e2
Author: trycode277 <dayanandks990@gmail.com>
Date:   Fri Dec 12 21:34:10 2025 +0530

    6 experimant


C:\Users\dayan\AI_assistant1.5->git log -n 1 e79f9e9
commit e79f9e963d43cf8930bfce2207ed7f02c5be3c34 (origin/main, origin/HEAD)
Author: Dayananda KS <dayanandks990@gmail.com>
Date:   Tue Dec 9 10:32:56 2025 +0530

    add one line

10.Experiment

C:\Users\dayan\AI_assistant1.5->git log --author="Dayananda KS" --since="2025-10-25" --until="2025-12-13"
commit e79f9e963d43cf8930bfce2207ed7f02c5be3c34 (origin/main, origin/HEAD)
Author: Dayananda KS <dayanandks990@gmail.com>
Date:   Tue Dec 9 10:32:56 2025 +0530

    add one line

commit c664aecdb0d0602061f50596860dd19692f5e14a
Author: Dayananda KS <dayanandks990@gmail.com>
Date:   Sat Dec 6 09:15:09 2025 +0530

    new commit for hello

commit 96a7885d8b0cb1baa985671236b5b6d4a933c3cf
Author: Dayananda KS <dayanandks990@gmail.com>
Date:   Sat Dec 6 09:15:09 2025 +0530

    new commit for hello

commit ca066eaa9dfcec7e311b265d6b974c764eced8e8
Author: Dayananda KS <dayanandks990@gmail.com>
Date:   Mon Dec 8 19:57:37 2025 +0530

    add java file

commit 549a9d764adf9f4190a815f1ca6963189b7e6471
Author: Dayananda KS <dayanandks990@gmail.com>
Date:   Mon Dec 8 19:57:37 2025 +0530

    add java file

commit aba9e700ec41f07ecaa6ef84567605ccc03f9317
Author: Dayananda KS <dayanandks990@gmail.com>
Date:   Sat Dec 6 09:15:09 2025 +0530

    Hello world

commit 5383f9189b81122628a9c89727b3f48c318af958 (tag: v1.0, tag: t1.0)
Author: Dayananda KS <dayanandks990@gmail.com>
Date:   Sat Dec 6 09:15:09 2025 +0530

:
commit e79f9e963d43cf8930bfce2207ed7f02c5be3c34 (origin/main, origin/HEAD)
Author: Dayananda KS <dayanandks990@gmail.com>
Date:   Tue Dec 9 10:32:56 2025 +0530

    add one line

commit c664aecdb0d0602061f50596860dd19692f5e14a
Author: Dayananda KS <dayanandks990@gmail.com>
Date:   Sat Dec 6 09:15:09 2025 +0530

    new commit for hello

commit 96a7885d8b0cb1baa985671236b5b6d4a933c3cf
Author: Dayananda KS <dayanandks990@gmail.com>
Date:   Sat Dec 6 09:15:09 2025 +0530

    new commit for hello

commit ca066eaa9dfcec7e311b265d6b974c764eced8e8
Author: Dayananda KS <dayanandks990@gmail.com>
Date:   Mon Dec 8 19:57:37 2025 +0530

    add java file

commit 549a9d764adf9f4190a815f1ca6963189b7e6471
Author: Dayananda KS <dayanandks990@gmail.com>
Date:   Mon Dec 8 19:57:37 2025 +0530

    add java file

commit aba9e700ec41f07ecaa6ef84567605ccc03f9317
Author: Dayananda KS <dayanandks990@gmail.com>
Date:   Sat Dec 6 09:15:09 2025 +0530

    Hello world

commit 5383f9189b81122628a9c89727b3f48c318af958 (tag: v1.0, tag: t1.0)
Author: Dayananda KS <dayanandks990@gmail.com>
Date:   Sat Dec 6 09:15:09 2025 +0530

11.Experiment

C:\Users\dayan\AI_assistant1.5->git log -n 5
commit 3084fc58fbc05aa51049fcb2dfaf0a0c76991505 (HEAD -> main)
Author: trycode277 <dayanandks990@gmail.com>
Date:   Fri Dec 12 21:42:34 2025 +0530

    hello

commit bce11239eccc11052fd1d79e5f28a281e3ce3abb
Merge: f5025d2 d1483e2
Author: trycode277 <dayanandks990@gmail.com>
Date:   Fri Dec 12 21:34:10 2025 +0530

    6 experimant

commit d1483e2e50c427623ce11bd8954d528ecb286f01
Author: trycode277 <dayanandks990@gmail.com>
Date:   Fri Dec 12 21:32:21 2025 +0530

    last massage

commit f5025d2dd1f0cf30992e342a4692fb66d044d726
Merge: e79f9e9 b55ec06
Author: trycode277 <dayanandks990@gmail.com>
Date:   Fri Dec 12 21:29:15 2025 +0530

    Merge branch 'feature-branch'

commit b55ec06387eb58e098b7a6e3727bb57152da7ff3
Author: trycode277 <dayanandks990@gmail.com>
Date:   Fri Dec 12 21:28:17 2025 +0530

    I create new data

12.Experiment

C:\Users\dayan\AI_assistant1.5->git revert a41963c
hint: Waiting for your editor to close the file...
[main dd70084] Revert "solving"
 2 files changed, 116 deletions(-)
 delete mode 100644 pyscript.json
 delete mode 100644 style.css
