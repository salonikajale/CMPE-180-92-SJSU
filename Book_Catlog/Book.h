
#include <string>
#include <iostream>

using namespace std;

/***** Complete this file. *****/

/**
 * The Book class.
 */
class Book
{
public:
    /**
     * Book categories.
     */
    enum class Category { FICTION, HISTORY, TECHNICAL, NONE };

    /**
     * Default constructor.
     */
    Book();

    /**
     * Constructor.
     */
    Book(string isbn, string last, string first, string title, string category);

    /**
     * Destructor.
     */
    ~Book();

    /***** Complete the public members. *****/

   friend ostream& operator << (ostream& output, const Book& B);
   friend istream& operator >> (istream& input, Book& B );
	
   const string getIsbn() const;

    const string getCategory() const;

    const string getAuthor() const;

    void set_category(string categ);

private:
    string isbn;
    string last;
    string first;
    string title;
    Category category;

    /***** Complete the private members. *****/
};

//#endif /* EMPLOYEE_H_ */
