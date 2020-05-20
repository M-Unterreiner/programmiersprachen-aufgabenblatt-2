* Aufgabenblatt 2
** Aufgabe 2.2
Welchen Zweck haben Include Guards in der .hpp Datei?
Include Guards haben den Zweck zu verhindern, dass Funktionen und Klassen mehrmals in der Header Datei eingeschlossen werden.
Sie werden auch als Header- oder Macro Guards bezeichnet. Sie arbeiten mit jedem Standard Kompiler und Präprozessor.

https://riptutorial.com/cplusplus/example/3525/include-guards

*** Datentransferobjekte:

Datentransferobjekte sind reine Datenstrukturen. In C++ werden als Datentransferobjekte das struct Konstrukt verwendet. Sie haben keine explizite Konstruktoren und auch keine Methoden

struct:
Eine Struktur ist ein Datentyp, der mehrere Variablen gleichen oder verschiedenen Typs zu einem neuen Datentyp zusammenfasst. Im Unterschied zur Klasse sind bei einer Struktur die Member standardmäßig public. Sie werden durch aggregate Initialisierung initialisiert. 



union können im Gegensatz zu struct mehrere Datentypen vereinen.
#+NAME: <struct>
#+BEGIN_SRC C++
// struct-Definition in der Header Datei circle.hpp 
struct ColorRGB { 
  float r=0.0f, g=0.0f, b=0.0f; 
};


// Instanziierung der strucs (in irgendwelchen cpp-Dateien)
ColorRGB c{0.0f,1.0f,0.0f};
#+END_SRC

*** Klassen

Wo werden die Klassen definiert? In der hpp?




** Aufgabe 2.8


















#+NAME: <name>
#+BEGIN_SRC <c++> <switches> <header arguments>
<body>
#+END_SRC
