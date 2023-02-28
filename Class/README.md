# CLASSES
Sınıflar veri yapılarının genişletilmiş şeklidir. Veri üyeleri ve fonksiyonlar içerebilirler. Bir nesne bir sınıfın örneğidir. Değişken olarak bakıldığında sınıf veri türü, nesne ise değişkendir.

```
class ClassName {
  access_specifier:
    member1;
  access_specifier:
    member2;
    //...
} object_names;
```

### Access Specifiers
* **private:** Sınıf dışınadan erişilemeyen ve görülemeyen üyeler.
* **public:** Nesnenin görünür olduğu her yerden erişilebilen üyeler.
* **protected:** Sınıf dışından erişilemeyen, ancak miras alınan (inherited) sınıflardan erişilebilen üyeler.

<br />

## Constructors (Yapıcılar)
```
class Rectangle {
  int width, height;
 public:
  Rectangle(int, int);  // constructor
  //Rectangle(int a, int b) : width(a), height(b){};
  //Rectangle(int a, int b) { width = a; height = b; } 
};

Rectangle::Rectangle(int a, int b) {
  width = a;
  height = b;
}
```

<br />

## Overloading Constructor (Aşırı Yüklemeli Yapıcılar)
```
class Rectangle {
  int width, height;
 public:
  Rectangle();          // constructor
  Rectangle(int, int);  // (overloading) constructor  
};

Rectangle::Rectangle() {
  width = 5;
  height = 8;
}

Rectangle::Rectangle(int a, int b) {
  width = a;
  height = b;
}
```


<br />

## Destructors (Yıkıcılar)
```
class Rectangle {
  int width, height;
 public:
  Rectangle(int, int);  // constructor
  ~Rectangle();         // destructor
};

Rectangle::Rectangle(int a, int b) {
  width = a;
	height = b;
}

Rectangle::~Rectangle() {
	cout << "Rectangle deleted" << endl;
}
```

<br />

## "Const" Üye Fonksiyonları
Bir sınıfın (class) bir nesnesi _const_ olarak tanımlanırsa bu nesnenin üyelerine (class member) erişim sınıf dışından sadece read-only olarak sınırlıdır. Yani bu nesnenin üyeleri de _const_ olarak algılanır.
	
**Dikkat!** _Const_ nesne, sınıfın üye fonksiyonlarını sadece fonksiyonlar _const_ olarak tanımlanmışsa çağırabilir. 


Bir üye fonksiyonun _const_ olduğu şu sekilde ifade edilir:
```
int get()const{ return x; }
```	      
_Const_ nesneler _const_ türündeki üye fonksiyonlara erişim sağlayabilir. _Non-const nesneler_ ise hem _const_ hem de _non-const_ üye fonksiyonlara erişim sağlayabilir.

