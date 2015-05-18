# !/bin/bash

file_dir="./time_3way_with_end"
for i in `seq 30`
do
	files=(${files[@]} benchmark_${i})
done
for i in gcc apache spins spinv bugzilla
do
	files=(${files[@]} benchmark_${i})
done

if [ ! -d tmp ]
then
	mkdir tmp
else
	rm -r tmp;
	mkdir tmp;
fi

for seed in `seq 1 10`
do
	for file in ${files[@]}
	do
		if [ ! -f "$file_dir/${file}_${seed}.time" ]
		then
			echo "no file $file_dir/${file}_${seed}.time"
			continue;
		fi
		run_time_file=./tmp/${file}_${seed}.time
		./rm_zero "$file_dir/${file}_${seed}.time" $run_time_file
	done
done

exit 0
out_file="all_2way.res"
if [ -f "$out_file" ]
then
	rm "$out_file";
fi
echo "instance avg_time min_size avg_size max_size cv_time(%) cv_size(%)" > $out_file
for file in ./tmp/*.time
do
	./stat $file summary;
	model_name="${file##*/}"
	model_name="${model_name%\.time}"
	str="$model_name "
	str="$str"`cat summary`
	echo $str >> $out_file;
done
rm summary
rm -r tmp
exit 0;
