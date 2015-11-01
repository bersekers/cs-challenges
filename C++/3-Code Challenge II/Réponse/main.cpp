#include <map>
#include <string>
#include <iostream>
#include <fstream>

void jsonify(std::map<std::string, unsigned int> & map, std::ostream & stream) {
    stream << "{" << std::endl;
    for(const auto& kv: map) {
        stream << "\"" << kv.first << "\": " << kv.second << "," << std::endl;
    }
    stream << "}";
}

std::map<std::string, unsigned int> count(std::istream & file) {
    std::string word;
    std::map<std::string, unsigned int> count;
    while (file >> word) {
        if (count.count(word) == 0)
            count[word] = 1;
        else
            count.at(word) += 1;
    }
    return count;
}

int main() {
    std::ifstream file{"data"};
    std::ofstream json{"output.json"};
    auto map = count(file);
    jsonify(map, json);
    json.close();
    return 0;
}
