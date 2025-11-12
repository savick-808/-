nested_list = [
    ["apple", "banana"],
    ["cherry", "grape"],
    ["mango", "kiwi"]
]

flat_list = []

# Проходим циклом по каждому внутреннему списку и добавляем элементы в flat_list
for inner_list in nested_list:
    for item in inner_list:
        flat_list.append(item)

print(flat_list)  # ['apple', 'banana', 'cherry', 'grape', 'mango', 'kiwi']