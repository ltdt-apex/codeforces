#! /bin/bash

template_file="template/template.cpp"
leetcode_contest_folder="question/leetcode/contest"
contest=$1

leetcode_contest_dir=$leetcode_contest_folder/$contest

cp "$template_file" temp.cpp
sed -i "/^void solve/,/^}/d" temp.cpp
sed -i "/^int main/,/^}/d" temp.cpp

mkdir -p $leetcode_contest_dir
cp -n temp.cpp $leetcode_contest_dir/q1.cpp
cp -n temp.cpp $leetcode_contest_dir/q2.cpp
cp -n temp.cpp $leetcode_contest_dir/q3.cpp
cp -n temp.cpp $leetcode_contest_dir/q4.cpp

rm temp.cpp

