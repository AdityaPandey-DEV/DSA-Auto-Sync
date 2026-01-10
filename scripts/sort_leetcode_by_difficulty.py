import os
import subprocess
import shutil

BASE_DIR = "leetcode"
EASY = os.path.join(BASE_DIR, "easy")
MEDIUM = os.path.join(BASE_DIR, "medium")
HARD = os.path.join(BASE_DIR, "hard")

os.makedirs(EASY, exist_ok=True)
os.makedirs(MEDIUM, exist_ok=True)
os.makedirs(HARD, exist_ok=True)

def get_difficulty(problem_slug):
    try:
        result = subprocess.check_output(
            ["leetcode", "show", problem_slug],
            stderr=subprocess.DEVNULL,
            text=True
        )
        for line in result.splitlines():
            if "Difficulty" in line:
                return line.split(":")[1].strip().lower()
    except Exception:
        return None

for file in os.listdir(BASE_DIR):
    if not file.endswith((".cpp", ".py", ".java")):
        continue

    slug = file.replace(".cpp", "").replace(".py", "").replace(".java", "")
    difficulty = get_difficulty(slug)

    if difficulty == "easy":
        target = EASY
    elif difficulty == "medium":
        target = MEDIUM
    elif difficulty == "hard":
        target = HARD
    else:
        print(f"⚠️ Skipping {file} (difficulty not found)")
        continue

    src = os.path.join(BASE_DIR, file)
    dst = os.path.join(target, file)

    if not os.path.exists(dst):
        shutil.move(src, dst)
        print(f"✅ Moved {file} → {difficulty}")