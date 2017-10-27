
#include <vector>
#include "Book.h"

Book::Book() {

}

Book::Book(string isbn, string last, string first, string title, string category) {
    this->isbn = isbn;
    this->last = last;
    this->first = first;
    this->title = title;
    this->set_category(category);
}

Book::~Book() {

}

const string Book::getIsbn() const {
    return isbn;
}

const string Book::getAuthor() const{
	return last;
}

const string Book::getCategory() const {
	string str;

	if(category == Category::FICTION)
		str = "fiction";
	else if(category == Category::HISTORY)
		str = "history";
	else if(category == Category::TECHNICAL)
		str = "technical";
	else
		str = "none";

	return str;
}

void Book::set_category(string categ)
{
if(categ == "fiction")
	category = Category::FICTION;
else if(categ == "history")
	category = Category::HISTORY;
else if(categ == "technical")
	category = Category::TECHNICAL;
else
	category = Category::NONE;

}

istream& operator >> (istream& input, Book &B) {
	string bk;
	getline(input,bk);
	vector<string> infos;
	string dem = ",";
	int pos = 0,i=0;
	while (i<=4) {
		pos=bk.find(dem);
	    infos.push_back(bk.substr(0, pos));
	    bk=bk.substr(pos+dem.length(),bk.length()-pos-dem.length());
	    i++;
	}
	B.isbn = infos[0].substr(1,infos[0].length()-1);
	B.last = infos[1];
	B.first = infos[2];
	B.title = infos[3];
    B.set_category(infos[4]);
    return input;
}

ostream& operator << (ostream& output, const Book& B)
{
	output << "Book{ISBN=" << B.isbn << ", last=" << B.last << ", first=" << B.first << ", title=" << B.title << ", category=" << B.getCategory() <<"}" << endl;
    return output;
}
 
