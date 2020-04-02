//CIS554 HW5 Due: 11:59pm, 3/27 Friday
//Read the description below.
#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;


template <class T> int Count(const list<int>& l, T F) {
    int count = 0;
    for (auto i : l) {
        if (F(i))
            count++;
    }
    return count;
}

bool Odd(int& i) {
    return (i % 2 != 0);
}

class even {
public:
    bool operator()(int& i) {
        return (i % 2 == 0);
    }
} Even ;

auto Three = [](int i) { return (i % 3 == 0); };

class myCompare1 {
public :
    bool operator()(const list<int*>* i, const list<int*>* j) const {
        int leftSum = 0;
        for (auto x : *i) {
            leftSum += *x;
        }
        int rightSum = 0;
        for (auto x : *j) {
            rightSum += *x;
        }
        return leftSum < rightSum;
    }
};

class myCompare2 {
public:
    bool operator()(const map<list<int*>*, vector<int*>, myCompare1>& i, const map<list<int*>*, vector<int*>, myCompare1>& j) const {
        int leftSum = 0;
        for (auto x : i) {
            for (auto y : *x.first) {
                leftSum += *y;
            }
            for (auto y : x.second) {
                leftSum += *y;
            }
        }
        int rightSum = 0;
        for (auto x : j) {
            for (auto y : *x.first) {
                rightSum += *y;
            }
            for (auto y : x.second) {
                rightSum += *y;
            }
        }
        return leftSum < rightSum;
    }
};

ostream& operator<<(ostream& str, const list<int*>& L) {
    str << "( ";
    for (auto i : L) {
        str << *i << " ";
    }
    str << ")";
    return str;
}


template <class T> ostream& operator<<(ostream& str, const list<T>& L) {
    str << "( ";
    for (auto i : L) {
        str << i << " ";
    }
    str << ")";
    return str;
}



template <class T> ostream& operator<<(ostream& str, const vector<T>& L) {
    str << "[ ";
    for (auto i : L) {
        str << *i << " ";
    }
    str << "]";
    return str;
}

template <class T, class J> ostream& operator<<(ostream& str, const map <T, J, myCompare1>& M) {
    str << "{ ";
    for (auto i : M) {
        str << (*(i.first)) << " " << (i.second) << " ";
    }
    str << "}";
    return str;
}

template <class T, class J> ostream& operator<<(ostream& str, const map< T, J, myCompare2>& M) {
    str << "{ ";
    for (auto i : M) {
        str << (i.first) << " " << (i.second) << " ";
    }
    str << "} ";
    return str;
}


//ostream& operator<<(ostream& str, const list<map < list<int*>*, vector<int*>, myCompare1 >>& L) {
//    str << "{ ";
//    for (auto i : L) {
//        for (auto j : i) {
//            str << j.first << " ";
//        }
//    }
//    str << "} ";
//    return str;
//}



int main() {
    /*
    Write 4 functions: Count, Odd, Even, and Three.
    The second argument for Count is function Odd, Even, or Three.
    It will count, in the list,  the number of odd elements,
    the number of even elements, or the number of multiples of 3 in the list.
    Count, and Odd are required to be implemented using regular function.
    Even is required to be implemented using functor.
    Three is required to be implemented using lambda
    */
    list<int> L0{ 14,7,2,6,9,5,8,2,13 };
    cout << Count(L0, Odd) << endl;
    cout << Count(L0, Even) << endl;
    cout << Count(L0, [](int i) { return (i % 3 == 0); }) << endl;
    cout << endl;


    /*
    Remember that map will always sort elements by comparing the first part of each element (i.e., the key part).
    Implement classes, myCompare1 and myCompare2, to allow the following map declaration to work.
    In both classes, when comparing two keys, count the sums of all int values at all levels, and compare the sums.
    */
    map<map<list<int*>*, vector<int*>, myCompare1>, int, myCompare2> M1
    {

            {   {
                        { new list<int*>{new int{10}, new int{20}, new int{30} }   , {new int{20}, new int{40}}   },
                        { new list<int*>{new int{40}, new int{20}, new int{30} }   , {new int{20}, new int{40}, new int{100}}   }
                } , 50
            },


            { {
                        { new list<int*>{new int{10}, new int{20}, new int{30} }   , {new int{20}, new int{40}}   },
                        { new list<int*>{new int{40}, new int{20}, new int{30} }   , {new int{20}, new int{40}, new int{200}}   }
                } , 100
            }



    };
    //Implement the needed overloading operator<< to support the following printing.
    cout << M1 << endl;
    cout << endl;


    /*
    For the following, implement the functions used
    in sorting the list elements using regular funciton, functor, and lambda in the three cases.
    Similar to the case of map, we will compare the sums of int values at all levels.
    In addition, you need to implement the needed overloaded operator<< to supporting the printing.
    */
    list<map < list<int*>*, vector<int*>, myCompare1 >> L1{ {
                                                                    {
                                                                            new list<int*>{new int{10}, new int{20}, new int{30} } ,
                                                                            {new int{20}, new int{400}}
                                                                    },

                                                                    {
                                                                            new list<int*>{new int{40}, new int{20}, new int{30} }   ,
                                                                            {new int{20}, new int{40}, new int{100}}
                                                                    }
                                                            } , {
                                                                    {
                                                                            new list<int*>{new int{10}, new int{20}, new int{30} } ,
                                                                            {new int{20}, new int{40}}
                                                                    },

                                                                    {
                                                                            new list<int*>{new int{40}, new int{20}, new int{30} }   ,
                                                                            {new int{20}, new int{40}, new int{200}}
                                                                    }
                                                            } };
    cout << L1 << endl;
    L1.sort();//???: use a regular function
    cout << L1 << endl;
    cout << endl;

    list<map < list<int*>*, vector<int*>, myCompare1 >> L2{ {
                                                                    {
                                                                            new list<int*>{new int{10}, new int{20}, new int{30} } ,
                                                                            {new int{20}, new int{400}}
                                                                    },

                                                                    {
                                                                            new list<int*>{new int{40}, new int{20}, new int{30} }   ,
                                                                            {new int{20}, new int{40}, new int{100}}
                                                                    }
                                                            } , {
                                                                    {
                                                                            new list<int*>{new int{10}, new int{20}, new int{30} } ,
                                                                            {new int{20}, new int{40}}
                                                                    },

                                                                    {
                                                                            new list<int*>{new int{40}, new int{20}, new int{30} }   ,
                                                                            {new int{20}, new int{40}, new int{200}}
                                                                    }
                                                            } };

    cout << L2 << endl;
    L2.sort();//???: use a functor
    cout << L2 << endl;
    cout << endl;

    list<map < list<int*>*, vector<int*>, myCompare1 >> L3{ {
                                                                    {
                                                                            new list<int*>{new int{10}, new int{20}, new int{30} } ,
                                                                            {new int{20}, new int{400}}
                                                                    },

                                                                    {
                                                                            new list<int*>{new int{40}, new int{20}, new int{30} }   ,
                                                                            {new int{20}, new int{40}, new int{100}}
                                                                    }
                                                            } , {
                                                                    {
                                                                            new list<int*>{new int{10}, new int{20}, new int{30} } ,
                                                                            {new int{20}, new int{40}}
                                                                    },

                                                                    {
                                                                            new list<int*>{new int{40}, new int{20}, new int{30} }   ,
                                                                            {new int{20}, new int{40}, new int{200}}
                                                                    }
                                                            } };

    cout << L3 << endl;
    L3.sort();//???: use a lambda
    cout << L3 << endl;

    return 0;
}
//The following is a sample screenshot
//You have to follow the exact format to avoid penalty in grading.
/*
4
5
2
{ { ( 10 20 30 ) [ 20 40 ] ( 40 20 30 ) [ 20 40 100 ] } 50 { ( 10 20 30 ) [ 20 40 ] ( 40 20 30 ) [ 20 40 200 ] } 100 }
( { ( 10 20 30 ) [ 20 400 ] ( 40 20 30 ) [ 20 40 100 ] } { ( 10 20 30 ) [ 20 40 ] ( 40 20 30 ) [ 20 40 200 ] } )
( { ( 10 20 30 ) [ 20 40 ] ( 40 20 30 ) [ 20 40 200 ] } { ( 10 20 30 ) [ 20 400 ] ( 40 20 30 ) [ 20 40 100 ] } )
( { ( 10 20 30 ) [ 20 400 ] ( 40 20 30 ) [ 20 40 100 ] } { ( 10 20 30 ) [ 20 40 ] ( 40 20 30 ) [ 20 40 200 ] } )
( { ( 10 20 30 ) [ 20 40 ] ( 40 20 30 ) [ 20 40 200 ] } { ( 10 20 30 ) [ 20 400 ] ( 40 20 30 ) [ 20 40 100 ] } )
( { ( 10 20 30 ) [ 20 400 ] ( 40 20 30 ) [ 20 40 100 ] } { ( 10 20 30 ) [ 20 40 ] ( 40 20 30 ) [ 20 40 200 ] } )
( { ( 10 20 30 ) [ 20 40 ] ( 40 20 30 ) [ 20 40 200 ] } { ( 10 20 30 ) [ 20 400 ] ( 40 20 30 ) [ 20 40 100 ] } )
*/