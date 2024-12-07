// #include <fstream>
// #include <iostream>
// #include <sstream>
// #include <vector>
// #include <numeric>
// #include <iterator>

// void process_input(std::ifstream &input) {
//   std::string line;
//   int count_line = 0;
//   int safe = 0;

//   while (std::getline(input, line)) {
//     count_line++;
//     std::cout << "Processing line: " << line << std::endl;

//     // Extraire les nombres dans un vecteur
//     std::vector<int> numbers;
//     std::stringstream ss(line);
//     numbers.assign(std::istream_iterator<int>(ss), std::istream_iterator<int>());

//     // Vérifier si le vecteur est vide ou a un seul élément
//     if (numbers.size() <= 1) {
//       safe++;
//       continue;
//     }

//     // Compteur pour les augmentations et diminutions
//     int count_increase = 0;
//     int count_decrease = 0;
//     int incoherent = 0;
//     int equal = 0;

//     // Utiliser std::adjacent_find pour détecter les incohérences
//     for (auto it = numbers.begin() + 1; it != numbers.end(); ++it) {
//       auto prev = *(it - 1);
//       auto curr = *it;

//       std::cout << "prev = " << prev << ", curr = " << curr;
//       if ((it + 1) != numbers.end()) {
//         std::cout << ", next = " << *(it + 1);
//       }
//       std::cout << std::endl;

//       if (prev < curr) {
//         std::cout << "isIncreased" << std::endl;
//         count_increase++;
//       } else if (prev > curr) {
//         std::cout << "isDecreased" << std::endl;
//         count_decrease++;
//       }

//       if (prev == curr) {
//         std::cout << "isEqual" << std::endl;
//         equal++;
//       }

//       // Vérifier la cohérence avec le prochain élément
//       if ((it + 1) != numbers.end() && (*(it + 1) - curr) != (curr - prev)) {
//         std::cout << "Incoherence detected" << std::endl;
//         incoherent++;
//       }
//     }

//     // Déterminer si la ligne est safe ou non
//     if (count_increase > 0 && count_decrease > 0) continue;
//     if (incoherent > 0 || equal > 0) continue;
//     safe++;
//   }

//   std::cout << "Number of safe lines: " << safe << std::endl;
//   std::cout << "Number of total lines: " << count_line << std::endl;
// }

// int main() {
//   std::ifstream input("day2_input.txt");
//   if (!input.is_open()) {
//     std::cerr << "Could not open the file" << std::endl;
//     return 1;
//   }

//   process_input(input);
//   input.close();
//   return 0;
// }

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib> // Pour atoi

bool is_safe_report(const std::vector<int>& levels) {
    // Vérifier si la différence entre deux niveaux adjacents est valide
    for (size_t i = 1; i < levels.size(); ++i) {
        int diff = std::abs(levels[i] - levels[i - 1]);
        if (diff < 1 || diff > 3) {
            return false; // Différence invalide
        }
    }

    // Vérifier si tous les niveaux sont croissants ou décroissants
    bool increasing = true;
    bool decreasing = true;
    for (size_t i = 1; i < levels.size(); ++i) {
        if (levels[i] < levels[i - 1]) {
            increasing = false;
        }
        if (levels[i] > levels[i - 1]) {
            decreasing = false;
        }
    }

    // Le rapport est sûr s'il est soit croissant, soit décroissant
    return increasing || decreasing;
}

void process_input(std::ifstream& input) {
    std::string line;
    int safe_reports = 0;
    int total_reports = 0;

    while (std::getline(input, line)) {
        total_reports++;

        std::stringstream ss(line);
        std::vector<int> levels;
        int level;

        // Convertir chaque nombre dans la ligne en un entier et le stocker dans le vecteur
        while (ss >> level) {
            levels.push_back(level);
        }

        // Vérifier si le rapport est sûr
        if (is_safe_report(levels)) {
            safe_reports++;
        }
    }

    std::cout << "Number of safe reports: " << safe_reports << std::endl;
    std::cout << "Total number of reports: " << total_reports << std::endl;
}

int main() {
    std::ifstream input("day2_input.txt");
    if (!input.is_open()) {
        std::cerr << "Could not open the file" << std::endl;
        return 1;
    }

    process_input(input);
    input.close();

    return 0;
}
