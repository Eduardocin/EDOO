#ifndef ARTICLE_H
#define ARTICLE_H

#include <string>

using namespace std;

class Article {
private:
    static int total_articles;
    long article_number;
    string article_name;
    double sales_price;

public:
    // Constructor with default arguments
    Article(long number = 0, const string& name = "", double price = 0.0);

    // Destructor
    ~Article();

    // Print the article
    void print();

    // Setters
    void set_sales_price(double price);
    void set_name(const string& name);
    void set_article_number(long number);

    // Getters
    double get_sales_price() const;
    string get_name() const;
    long get_article_number() const;
};

#endif