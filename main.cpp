#include <iostream>
#include <string>
#include <list>
#include <ctime>

class TodoItem
{
private:
    int id;
    std::string description;
    bool completed;

public:
    TodoItem() : id(0), description(""), completed(false) {}
    ~TodoItem() = default;

    bool create(std::string new_description)
    {
        // generates a random integer between 1 and 100
        id = rand() % 100 + 1;
        description = new_description;
        return true;
    }

    int getId() { return id; }
    std::string getDescription() { return description; }
    bool isCompleted() { return completed; }

    void setCompleted(bool val) { completed = val; }
};

int main()
{
    char input_option;
    int input_id;
    std::string input_description;
    std::string version = "v0.2.0";
    std::list<TodoItem> todoItems;
    std::list<TodoItem>::iterator it;

    srand(time(NULL));

    todoItems.clear();

    while (1)
    {
        system("cls");
        std::cout << "Todo List Maker - " << version << std::endl;
        std::cout << std::endl
                  << std::endl;

        for (it = todoItems.begin(); it != todoItems.end(); it++)
        {

            std::string completed = it->isCompleted() ? "done" : "not done";

            std::cout << it->getId() << " | " << it->getDescription() << " | "
                      << completed << std::endl;
        }

        if (todoItems.empty())
        {
            std::cout << "Add your first todo!" << std::endl;
        }

        std::cout << std::endl
                  << std::endl;

        std::cout << "[a]dd a new Todo" << std::endl;
        std::cout << "[c]omplete a Todo" << std::endl;
        std::cout << "[q]uit" << std::endl;

        std::cout << "choice: ";

        std::cin >> input_option;

        if (input_option == 'q')
        {
            std::cout << "Have a great day now!" << std::endl;
            break;
        }
        else if (input_option == 'a')
        {
            std::cout << "Add a new description: ";
            std::cin.clear();
            std::cin.ignore();
            std::getline(std::cin, input_description);

            TodoItem newItem;
            newItem.create(input_description);
            todoItems.push_back(newItem);
        }
        else if (input_option == 'c')
        {
            std::cout << "Enter id to mark completed: ";
            std::cin >> input_id;

            for (it = todoItems.begin(); it != todoItems.end(); it++)
            {

                if (input_id == it->getId())
                {
                    it->setCompleted(true);
                    break;
                }
            }
        }
    }

    return 0;
}