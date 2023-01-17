# ParallelLocalMapReduce

This program uses "std::async" and "std::future" to run the "map_function" in parallel on multiple threads, each thread reads the contents of a file and returns an unordered_map with the count of each word.

The "reduce_function" takes a vector of these unordered_maps and returns an unordered_map containing each word and the total number of occurrences across all files.

The "main" function applies the "map_function" to each file in a vector of file names using "std::async" and "std::future" and waits for the result, then applies the "reduce_function" to the resulting vector.

Note that this example uses C++11 features and C++14 standard library, and it is not a distributed MapReduce program but it uses parallelism to perform the task.

To create a distributed MapReduce program in C++ would involve using a framework such as Apache Hadoop or Apache Spark, which provide the necessary infrastructure for running distributed computations. 
