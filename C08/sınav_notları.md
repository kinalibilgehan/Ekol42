# Sınav Notları

Bu notlar, C programlamada header guard (başlık koruması), makrolar, üçlü operatör (ternary operator), typedef, yapılar (structures), dinamik bellek yönetimi, NULL sonlandırılmış diziler, işaretçiler (pointers), `char **av` kullanımı, hata kontrolü ve recursive free konularının ne olduğunu, ne işe yaradığını ve nasıl kullanıldığını açıklamaktadır.



## Header Guard

### Amaç:
*   **Birden Fazla Dahil Etmeyi Önlemek:** Bir C projesinde, aynı header dosyasının (`.h` uzantılı) birden çok kez dahil edilmesi (include edilmesi) sorunlara yol açabilir. Bu, özellikle birbirine bağlı header dosyaları kullanıldığında sık karşılaşılan bir durumdur.
*   **Derleme Hatalarını Önlemek:** Bir header dosyası birden çok kez dahil edildiğinde, aynı yapıların, değişkenlerin veya fonksiyonların birden çok kez tanımlanmasına neden olabilir. Bu da derleme hatalarına (örneğin, "redefinition of..." hatası) yol açar.

### Kullanım
Header guard, ön işlemci direktifleri kullanılarak uygulanır. Genellikle şu şekilde bir kalıp kullanılır:
```
c
#ifndef HEADER_DOSYASI_ADI_H
#define HEADER_DOSYASI_ADI_H

// Header dosyasının içeriği (yapılar, fonksiyon prototipleri, vb.)

#endif
```
**Açıklama:**

1.  **`#ifndef HEADER_DOSYASI_ADI_H`:** Bu satır, `HEADER_DOSYASI_ADI_H` adlı makronun daha önce tanımlanıp tanımlanmadığını kontrol eder. `ifndef`, "if not defined" (tanımlanmamışsa) anlamına gelir.
2.  **`#define HEADER_DOSYASI_ADI_H`:** Eğer `HEADER_DOSYASI_ADI_H` makrosu tanımlanmamışsa, bu satır ile tanımlanır.
3. **`#endif`**: Ifndef ile başlayan bloğun sonunu işaretler.
4.  **`HEADER_DOSYASI_ADI_H` İsimlendirme:** Bu makro adı, genellikle header dosyasının adı ile uyumlu ve benzersiz olmalıdır. Örneğin, `my_file.h` için `MY_FILE_H` kullanılabilir.

### Nasıl Çalışır?
1.  Bir header dosyası ilk kez dahil edildiğinde, `#ifndef` kontrolü `true` olur çünkü makro henüz tanımlanmamıştır.
2.  `#define` ile makro tanımlanır ve header dosyasının içeriği derlemeye dahil edilir.
3.  Aynı header dosyası tekrar dahil edildiğinde, `#ifndef` kontrolü `false` olur çünkü makro artık tanımlıdır. Bu nedenle, `#endif` satırına kadar olan içerik derlemeye dahil edilmez.
4. Sadece bir kere dahil edilmiş gibi çalışır.

## Makrolar (Macros)

### Amaç:
*   **Kod Tekrarını Azaltmak:** Sık kullanılan ifadeleri veya sabit değerleri makro olarak tanımlayarak, kod tekrarını azaltır.
*   **Kodun Okunabilirliğini Artırmak:** Karmaşık ifadeleri anlamlı makro isimleri ile temsil ederek kodun okunabilirliğini artırır.
*   **Koşullu Derleme:** `#ifdef`, `#ifndef`, `#else`, `#endif` gibi ön işlemci direktifleri ile birlikte kullanılarak kodun farklı koşullara göre derlenmesini sağlar.

### Çeşitleri

1.  **Nesne Benzeri Makrolar:** Sabit değerler veya basit ifadeler için kullanılır.
```
c
    #define PI 3.14159
    #define MAX_SIZE 100
    
```
2.  **Fonksiyon Benzeri Makrolar:** Fonksiyon gibi davranan, argüman alabilen makrolardır.
```
c
    #define KARE(x) ((x) * (x))
    #define MAX(a, b) ((a) > (b) ? (a) : (b))
    
```
### Kullanım

*   **`#define`:** Bir makro tanımlamak için kullanılır.
*   **Makro İsmi:** Makro ismi genellikle büyük harflerle yazılır.
* **Makro Parametreleri:** Fonksiyon benzeri makrolar parametre alabilirler.

### Dikkat Edilmesi Gerekenler

*   **Parantez Kullanımı:** Fonksiyon benzeri makrolarda, argümanlar ve makro ifadesi içerisinde gereksiz görünen parantezler kullanılmalıdır. Bu, operatör önceliği ile ilgili beklenmedik sorunları önler.
*   **Yan Etkiler:** Fonksiyon benzeri makrolarda, argümanlar birden fazla kez değerlendirilebileceği için, yan etkisi olan ifadeler (örneğin `i++`) argüman olarak kullanılmamalıdır.

## Sonuç
*   **Koşullu İfadeleri Kısaltmak:** `if-else` yapısına alternatif olarak, basit koşullu ifadelerde kod satırını kısaltmak için kullanılır.
*   **Okunabilirliği Artırmak:** Basit koşullarda `if-else` yapısı yerine kullanıldığında, kod daha kısa ve öz olur, okunabilirliği artırır.

### Sözdizimi


Header guard ve makrolar, C programlamada kodun daha organize, okunabilir ve verimli olmasını sağlayan önemli araçlardır. Özellikle büyük projelerde, bu araçların doğru ve etkili bir şekilde kullanılması, derleme sürecini kolaylaştırır ve hataları önler.
## Üçlü (Ternary) Operatör

### Amaç:

*   **Koşullu İfadeleri Kısaltmak:** `if-else` yapısına alternatif olarak, basit koşullu ifadelerde kod satırını azaltmak için kullanılır.
*   **Okunabilirliği Artırmak:** Basit koşullarda `if-else` yapısı yerine kullanıldığında, kod daha kısa ve öz olur, okunabilirliği artırır.

### Sözdizimi:




## typedef

### Amaç

*   **Özel Veri Tipleri Tanımlamak:** `typedef` anahtar kelimesi, var olan bir veri türü için yeni bir isim (alias) tanımlamak amacıyla kullanılır.
*   **Kodun Okunabilirliğini Artırmak:** Karmaşık veri türlerini (örneğin, yapı işaretçileri veya fonksiyon işaretçileri) daha anlamlı isimlerle temsil ederek kodun okunabilirliğini artırır.
*   **Kodun Taşınabilirliğini Kolaylaştırmak:** Farklı sistemlerde farklı boyutlara sahip olabilen veri türlerinin (örneğin `int` veya `long`) daha kolay yönetilmesini sağlar.

### Kullanım

`typedef` anahtar kelimesi şu şekilde kullanılır:

## Yapılar (Structures)

### Amaç
* **Farklı Veri Tiplerini Gruplamak:** `struct` anahtar kelimesi, farklı veri tiplerini (int, char, float vb.) tek bir isim altında bir araya getirmek için kullanılır. Bu, ilgili verileri organize bir şekilde saklamayı ve yönetmeyi sağlar.
* **Özel Veri Türleri Oluşturmak:** Yapılar, karmaşık veri yapıları oluşturmak için kullanılabilir. Örneğin, bir öğrencinin adını, numarasını ve notlarını saklamak için bir yapı oluşturulabilir.

### Kullanım

