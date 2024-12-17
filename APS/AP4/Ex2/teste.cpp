#include <iostream>
#include <string>

using namespace std;

class Article
{
    private:
        static int total_articles;
        long article_number;
        string article_name;
        double sales_price;
    public:
        Article(long number = 0, const string& name = "", double price = 0.0)
            : article_number(number), article_name(name), sales_price(price) {
                total_articles++;
            }

        ~Article(){
            total_articles--;
        };

        inline void print() {
            cout << "Article number: " << article_number << endl;
            cout << "Article name: " << article_name << endl;
            cout << "Sales price: " << sales_price << endl;
        }

        inline void set_sales_price(double price) {
            sales_price = price;
        }

        inline void set_name(const string& name) {
            article_name = name;
        }
};

// Initialize the static member variable
int Article::total_articles = 0;

int main(){
    Article a1(1, "Article 1", 10.0);
    a1.print();
    a1.set_sales_price(20.0);
    a1.set_name("Article 1 modified");
    a1.print();

    return 0;
}
