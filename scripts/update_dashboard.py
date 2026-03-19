import os
from datetime import datetime
from collections import defaultdict

ROOTS = {
    "LeetCode": "leetcode",
    "Codeforces": "codeforces",
    "GeeksforGeeks": "geeksforgeeks",
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


def main():
    overall = defaultdict(int)
    platform_data = {}

    for platform, path in ROOTS.items():
        if not os.path.exists(path):
            continue
        data = count_monthly(path)
        platform_data[platform] = data
        for month, count in data.items():
            overall[month] += count

    dashboard = []
    dashboard.append("# ⚡ CP Progress Sync Dashboard\n")
    dashboard.append(f"> _Auto-updated on {datetime.now().strftime('%d %b %Y')}_\n")

    # Check if there is data
    if not overall:
        dashboard.append("No data available yet.")
        with open("dashboard.md", "w") as f:
            f.write("\n".join(dashboard))
        return

    # Prepare data for Mermaid chart
    sorted_months = sorted(overall.keys())
    counts = [overall[m] for m in sorted_months]

    months_str = ", ".join(f'"{m}"' for m in sorted_months)
    counts_str = ", ".join(str(c) for c in counts)
    max_count = max(counts) if counts else 10
    # Add a bit of padding to the max y-axis
    y_max = max_count + (5 - max_count % 5 if max_count % 5 != 0 else 5)
    dashboard.append("## 🔥 Progress Activity Overview")
    dashboard.append('<div align="center">\n')
    dashboard.append("```mermaid")
    dashboard.append("xychart-beta")
    dashboard.append('    title "Problems Solved per Month"')
    dashboard.append(f"    x-axis [{months_str}]")
    dashboard.append(f'    y-axis "Solved Count" 0 --> {y_max}')
    dashboard.append(f"    bar [{counts_str}]")
    dashboard.append(f"    line [{counts_str}]")
    dashboard.append("```")
    dashboard.append("\n</div>\n")
    dashboard.append("## 🌟 Overall Monthly Progress\n")
    dashboard.append("| Month | Problems Solved |")
    dashboard.append("| :--- | :---: |")
    for month in sorted_months:
        dashboard.append(f"| **{month}** | {overall[month]} |")
    dashboard.append("")
    dashboard.append("## 🎯 Platform Breakdown\n")
    for platform, data in platform_data.items():
        if not data:
            continue
        dashboard.append(f"### {platform}")
        dashboard.append("| Month | Problems Solved |")
        dashboard.append("| :--- | :---: |")
        for month in sorted(data):
            dashboard.append(f"| **{month}** | {data[month]} |")
        dashboard.append("")

    with open("dashboard.md", "w", encoding="utf-8") as f:
        f.write("\n".join(dashboard))


if __name__ == "__main__":
    main()
