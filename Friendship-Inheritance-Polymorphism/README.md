# FRIENDSHIP AND INHERITANCE
Temelde, bir sınıfın "private" ve "protected" üyelerine, deklare edildikleri sınıfın dışından erişilemez. Ancak bu kural arkadaş fonksiyonlar (friend functions) ve arkadaş sınıflar (friend classes) için geçerli değildir.  

"friend" fonksiyon ve sınıflar "friend" anahtar kelimesi (keyword) ile deklare edilir. 

<br />

## Friend Functions (Arkadaş Fonksiyonlar)
Bir sınıfın üyesi olmayan bir fonksiyon (non-member function), o sınıfın "private" ve "protected" üyelerine yine o sınıfın arkadaşı (friend) olarak deklare edilirse erişebilir. Arkadaş fonksiyon deklarasyonu, o fonksiyonun önüne "friend" yazılarak gerçekleştirilir.  

```
class Rectangle {
    int width, height;	    
  public:
    Rectangle(){};
    Rectangle(int x, int y) : width(x), height(y){};
    int area(){ return width * height; }
    friend Rectangle duplicate(const Rectangle&);
};
```

<br />

## Friend Classes (Arkadaş Fonksiyonlar)
Arkadaş fonksiyonlarda olduğu gibi arkadaş sınıfların üyeleri başka bir sınıfın "private" ve "protected" üyelerine erişebilir.  

```
class Square;

class Rectangle {
    int width, height;
  public:
    int area() { return (width * height); }
    void convert(Square a);
};

class Square {
  friend class Rectangle;
  private:
    int side;
  public:
    Square(int a) : side(a){};
};
```

<br />

## Inheritance Between Classes (Sınıflar Arası Devralmalar)
C++ dilinde sınıflar, temel sınıfın (base class) karakteristiğini koruyan yeni sınıflar oluşturarak genişletilir. Bu işlem devralma (inheritace) olrak bilinir ve temel sınıf (base class) ve türetilen sınıftan (derived class) oluşur. Türetilen sınıf (derived class), temel sınıfın (base class) üyelerini devralır ve kendi üyelerine ekler.

<br />

Base class (temel sınıf):
```
class Polygon {
  protected:
    int width, height;
  public:
    void set_values(int a, int b) { width = a; height = b; }
};
```

Türetilen sınıf (derived class):
```
class Rectangle: public Polygon {
  public:
    int area() { return width * height; }
};
```

Bir diğer türetilen sınıf (derived class):
```
class Triangle: public Polygon {
  public:
    int area() { return width * height / 2; }
};
```

**ÖNEMLİ:** Bu örneğe göre herhangi bir sınıfın (Polygon, Square, Triangle) kendi üyelerinin hepsine (private, prtected, public) erişir.

Türetilmiş sınıflar (derived class) "Polygon" sınıfının "public" ve "protected" üyelerine erişebilir. Bunun sebebi ise devralma seviyesinin "public" olmasıdır.
```
class Rectangle: public Polygon; 
class Triangle: public Polygon;
```

<br />
<br />

Devralma (inheritance) seviyesi "public" olabileceği gibi "private" ya da "protected" da olabilir.

Temelde, "public" olarak türetilen bir sınıf (derived class), temel sınıfın (base class);
* "constructor" ve "destructor" üyeleri,
* "friend" üyeleri,
* "private" üyeleri

dışındaki üyelerine erişebilir.  

Temel sınıfın (base class) "constructor" ve "destructor" üyelerine erişilemese de temel sınıfın (base class) "constructor" ve "destructor" üyeleri, türetilen sınıfın (derived class) "constructor" ve "destructor" üyeleri ile otomtik olarak çağrılır.  

<br />

## Multiple Inheritance (Çoklu Devralmalar)
Br sınıf, birden fazla temel sınıftan (base class) devralma (inheritance) işlemi gerçekleştirebilir.  
```
class Triangle: public Polygon, public Output {
  public:
    Triangle (int a, int b) : Polygon(a,b){};
    int area ()
      { return width * height / 2; }
};
```  

<br />

<br />

# POLYMORPHISM
## Pointers to Base Class (Temel Sınıfa İşaret Eden Göstericiler)
Türetilmiş sınıfa (derived class) işaret eden bir pointer, o sınıfın temel sınıfın (base class) işaret eden bir pointer ile tür uyumludur (type-compatible). Çok biçimcilik (polymorphism) bu basit, kuvvetli ve çok yönlü özelliğin avantajlarının kullanıldığı bir sanattır!

```
class Polygon {
  protected:
    int width, height;
  public:
    void set_values(int a, int b) { width=a; height=b; }
};

class Rectangle: public Polygon {
  public:
    int area() { return width * height; }
};

class Triangle: public Polygon {
  public:
    int area() { return width * height / 2; }
};


int main() {
  Rectangle rect;
  Triangle trgl;
```
_"rect" ve "trgl" nesnelerinin sınıfları "Polygon" sınıfından türetildikleri için "Polygon" sınıfı türünde bir pointer ile işaret edilebilirler._
```  
  Polygon* ppoly1 = &rect;
  Polygon* ppoly2 = &trgl;
```
_"ppoly1" ve "ppoly2" göstericileri (pointer) "Polygon" sınıfını işaret ediyor. Dolayısıyla "Polygon" sınıfından devralınan (inherited) üyelere erişim sağlayabilirler._
```  
  ppoly1->set_values(4, 5);  // rect.set_values(4, 5);
  ppoly2->set_values(4, 5);  // trgl.set_values(4, 5);
```
_Fakat burada `ppoly1->area();` ve `ppoly2->area();` yazılamaz._
```
  return 0;
}
```

<br />

## Virtual Members (Sanal Üyeler)
Sanal bir üye (virtual member), türetilen sınıfta (derived class) tekrardan tanımlanabilen üye bir fonksiyondur.

```
class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b) { width = a; height = b; }
    virtual int area() { return 0; }
};

class Rectangle: public Polygon {
  public:
    int area() { return width * height; }
};

class Triangle: public Polygon {
  public:
    int area() { return width * height / 2; }
};


int main() {
  Rectangle rect;
  Triangle trgl;
  Polygon poly;
  
  Polygon* ppoly1 = &rect;
  Polygon* ppoly2 = &trgl;
  Polygon* ppoly3 = &poly;
  
  ppoly1->set_values (4,5);
  ppoly2->set_values (4,5);
  ppoly3->set_values (4,5);
```
_"Polygon" sınıfı sanal (virtual) bir "area" fnksiyonuna sahip olduğu için `ppoly1->area();` ve `ppoly2->area();` yazılabilir._
```
  cout << ppoly1->area() << '\n';
  cout << ppoly2->area() << '\n';
  cout << ppoly3->area() << '\n';
  
  return 0;
}
```

<br />

## Abstract Base Classes (Soyut Temel Sınıflar)
Soyut temel sınıflar (abstract base class) sadece temel sınıf (base class) olarak kullanılabilirler. Dolayısıyla tanımı olmayan sanal üye fonksiyonlara (virtual member function without definition) sahip olmalarına izin verilir. Bu fonksiyonlar, saf sanal fonksiyonlar (pure virtual functions) olrak bilinirler.

```
class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b) { width = a; height = b; }
    virtual int area (void) = 0;
};
``` 
En az iki tane saf sanal fonksiyona (pure virtual function) sahip bir sınıf, soyut temel sınıftır (abstract base class).

`Polygon poly;` deklare edilemez. Çünkü "Polygon" sınıfı soyut temel sınıftır (abstract base class).