# Здесь вы можете создавать свои исполняемые файлы (executables)
# исполянемый файл = контрольный тест

# Пример создания контрольного теста (исполняемого файла) под названием demo_benchmark.
# Исходный код предоставлен в файле demo_benchmark.cpp текущей директории.
add_executable(demo_benchmark demo_benchmark.cpp)
add_executable(add_benchmark add_benchmark.cpp)
add_executable(get_benchmark get_benchmark.cpp)

# Примечание: Не забываем подключить (прилинковать) библиотеку ${PROJECT_NAME} с реализацией структуры данных.
target_link_libraries(demo_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(add_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(get_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
