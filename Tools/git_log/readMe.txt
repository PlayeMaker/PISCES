# 默认导出全部普通提交
python checkLists.py

# 指定输出文件名
python checkLists.py -o my_commits.xlsx

# 导出最近 50 条
python checkLists.py -n 50

# 按日期范围
python checkLists.py --since "2026-06-01"

# 按作者筛选
python checkLists.py --author "张三"

# 包含合并提交
python checkLists.py --include-merges