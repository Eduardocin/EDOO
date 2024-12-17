#include <iostream>
#include "article.h"

using namespace std;

// Inicialização do membro estático
int Article::total_articles = 0;

// Construtor
Article::Article(long number, const string& name, double price)
    : article_number(number), article_name(name), sales_price(price) {
    total_articles++;
    cout << "An object of type Article is created." << endl;
}

// Destrutor
Article::~Article() {
    total_articles--;
    cout << "An object of type Article is destroyed." << endl;
}

// Função para imprimir o artigo
void Article::print() {
    cout << "Article number: " << article_number << endl;
    cout << "Article name: " << article_name << endl;
    cout << "Sales price: " << sales_price << endl;
    cout << "Total number of articles: " << total_articles << endl;
}

// Setters
void Article::set_sales_price(double price) {
    sales_price = (price > 0 ? price : 0.0);
}

void Article::set_name(const string& name) {
    article_name = name;
}

void Article::set_article_number(long number) {
    article_number = number;
}

// Getters
double Article::get_sales_price() const {
    return sales_price;
}

string Article::get_name() const {
    return article_name;
}

long Article::get_article_number() const {
    return article_number;
}
