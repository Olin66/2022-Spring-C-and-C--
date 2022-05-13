typedef unsigned long Item;

class Stack
{
private:
    enum {MAX = 10};
    Item *pitems;
    int size;
    int top;
public:
    Stack(int n = MAX);
    Stack(const Stack &st);
    ~Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item &item);
    bool pop(Item &item);
    Stack & operator=(const Stack &st);
};

Stack::Stack(int n){
    this->size = n;
    this->top = 0;
    pitems = new Item[n];
}

Stack::Stack(const Stack &st){
    this->size = st.size;
    this->top = st.top;
    this->pitems = new Item[this->size];
    for (int i = 0; i < top; i++)
        this->pitems[i] = st.pitems[i];
}

Stack::~Stack(){
    delete[] pitems;
}

bool Stack::isempty() const{
    return top==0;
}

bool Stack::isfull() const{
    return top==size;
}

bool Stack::push(const Item &item){
    if (this->isfull())
        return false;
    this->pitems[top++] = item;
    return true;
}

bool Stack::pop(Item &item){
    if (this->isempty())
        return false;
    item = this->pitems[--top];
    return true;
}

Stack& Stack::operator=(const Stack &st){
    if (this == &st)
        return *this;
    delete[] pitems;
    this->size = st.size;
    this->top = st.top;
    this->pitems = new Item[this->size];
    for (int i = 0; i < top; i++)
        this->pitems[i] = st.pitems[i];
    return *this;
}