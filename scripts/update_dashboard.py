import os
from datetime import datetime
from collections import defaultdict

ROOTS = {
    "LeetCode": "leetcode",
    "Codeforces": "codeforces",
    "GeeksforGeeks": "geeksforgeeks"
}

def count_monthly(root):
    monthly = defaultdict(int)
    for base, _, files in os.walk(root):
        for f in files:
            if f.endswith((".cpp", ".py", ".java")):
                path = os.path.join(base, f)
                ts = os.path.getmtime(path)
                month = datetime.fromtimestamp(ts).strftime("%Y-%m")
                monthly[month] += 1
    return monthly

dashboard = []
dashboard.append("# 📊 DSA Monthly Progress Dashboard\n")
dashboard.append(f"_Auto-updated on {datetime.now().strftime('%d %b %Y')}_\n")

overall = defaultdict(int)

for platform, path in ROOTS.items():
    data = count_monthly(path)
    dashboard.append(f"## {platform}\n")
    for month in sorted(data):
        dashboard.append(f"- **{month}**: {data[month]} problems")
        overall[month] += data[month]
    dashboard.append("")

dashboard.append("## 📈 Overall Monthly Progress\n")
for month in sorted(overall):
    dashboard.append(f"- **{month}**: {overall[month]} problems")

with open("dashboard.md", "w") as f:
    f.write("\n".join(dashboard))