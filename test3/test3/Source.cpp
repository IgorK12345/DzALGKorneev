#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <shellSort.cpp>
#include <quickSort.cpp>



#define TEST_SORT_FUNCTION(FUNC_NAME) \
TEST_CASE(#FUNC_NAME " Tests", "[" #FUNC_NAME "]") { \
    \
    SECTION("Пустой вектор") { \
        std::vector<int> vec; \
        FUNC_NAME(vec); \
        REQUIRE(vec.empty()); \
    } \
    \
    SECTION("Один элемент") { \
        std::vector<int> vec = {5}; \
        FUNC_NAME(vec); \
        REQUIRE(vec.size() == 1); \
        REQUIRE(vec[0] == 5); \
    } \
    \
    SECTION("Уже отсортированный массив") { \
        std::vector<int> vec = {1, 2, 3, 4, 5}; \
        FUNC_NAME(vec); \
        REQUIRE(std::is_sorted(vec.begin(), vec.end())); \
    } \
    \
    SECTION("Обратно отсортированный массив") { \
        std::vector<int> vec = {5, 4, 3, 2, 1}; \
        FUNC_NAME(vec); \
        REQUIRE(std::is_sorted(vec.begin(), vec.end())); \
    } \
    \
    SECTION("Случайный массив") { \
        std::vector<int> vec = {3, 1, 4, 1, 5, 9, 2}; \
        FUNC_NAME(vec); \
        REQUIRE(std::is_sorted(vec.begin(), vec.end())); \
    } \
    \
    SECTION("Массив с дубликатами") { \
        std::vector<int> vec = {2, 2, 1, 1, 3, 3}; \
        FUNC_NAME(vec); \
        REQUIRE(std::is_sorted(vec.begin(), vec.end())); \
    } \
    \
    SECTION("Отрицательные числа") { \
        std::vector<int> vec = {-5, -1, -3, 0, 2, -2}; \
        FUNC_NAME(vec); \
        REQUIRE(std::is_sorted(vec.begin(), vec.end())); \
    } \
    \
    SECTION("Большой массив") { \
        std::vector<int> vec(1000); \
        for (size_t i = 0; i < vec.size(); ++i) { \
            vec[i] = static_cast<int>(vec.size() - i); \
        } \
        FUNC_NAME(vec); \
        REQUIRE(std::is_sorted(vec.begin(), vec.end())); \
    } \
    \
    SECTION("Тип int") { \
        std::vector<int> vec = {3, 1, 4, 1, 5}; \
        FUNC_NAME(vec); \
        REQUIRE(std::is_sorted(vec.begin(), vec.end())); \
    } \
    \
    SECTION("Тип double") { \
        std::vector<double> vec = {3.1, 1.5, 4.2, 1.1, 5.8}; \
        FUNC_NAME(vec); \
        REQUIRE(std::is_sorted(vec.begin(), vec.end())); \
    } \
    \
    SECTION("Тип float") { \
        std::vector<float> vec = {3.1f, 1.5f, 4.2f, 1.1f, 5.8f}; \
        FUNC_NAME(vec); \
        REQUIRE(std::is_sorted(vec.begin(), vec.end())); \
    } \
    \
    SECTION("Тип char") { \
        std::vector<char> vec = {'d', 'a', 'c', 'b'}; \
        FUNC_NAME(vec); \
        REQUIRE(std::is_sorted(vec.begin(), vec.end())); \
    } \
    \
    SECTION("Символы char") { \
        std::vector<char> vec = {'z', 'a', 'm', 'b', 'A', 'Z'}; \
        FUNC_NAME(vec); \
        REQUIRE(std::is_sorted(vec.begin(), vec.end())); \
    } \
}


TEST_SORT_FUNCTION(shellSort)
TEST_SORT_FUNCTION(quickSort)


int main(int argc, char* argv[]) {
    int result = Catch::Session().run(argc, argv);


    return 0;
}