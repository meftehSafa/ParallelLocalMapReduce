#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <thread>
#include <future>

std::unordered_map<std::string, int> map_function(const std::string& file_name) {
    std::unordered_map<std::string, int> word_counts;
    std::ifstream file(file_name);
    std::string word;
    while (file >> word) {
        ++word_counts[word];
    }
    return word_counts;
}

std::unordered_map<std::string, int> reduce_function(const std::vector<std::unordered_map<std::string, int>>& word_counts) {
    std::unordered_map<std::string, int> total_counts;
    for (const auto& count : word_counts) {
        for (const auto& [word, word_count] : count) {
            total_counts[word] += word_count;
        }
    }
    return total_counts;
}

int main() {
    std::vector<std::string> file_list = {"file1.txt", "file2.txt", "file3.txt"};
    std::vector<std::future<std::unordered_map<std::string, int>>> futures;
    for (const auto& file : file_list) {
        futures.push_back(std::async(std::launch::async, map_function, file));
    }
    std::vector<std::unordered_map<std::string, int>> word_counts;
    for (auto& future : futures) {
        word_counts.push_back(future.get());
    }
    auto total_counts = reduce_function(word_counts);
    for (const auto& [word, count] : total_counts) {
        std::cout << word << ": " << count << std::endl;
    }
    return 0;
}
