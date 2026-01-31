import os


def count_files(path):
    count = 0
    for root, _, files in os.walk(path):
        count += len([f for f in files if f.endswith((".cpp", ".py", ".java"))])
    return count


stats = {
    "leetcode": count_files("leetcode"),
    "codeforces": count_files("codeforces"),
    "geeksforgeeks": count_files("geeksforgeeks"),
}

with open("stats.json", "w") as f:
    f.write(str(stats))
