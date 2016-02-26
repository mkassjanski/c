/*

  Wykorzystując listę „dane” zawartą w pliku „package.scala” rozwiąż poniższe
  ćwiczenie – swój kod kompiluj za pomocą polecenia:

  scalac *.scala

  Lista zawiera informacje na temat „operacji bankowych” – jej elementami
  są pary data - kwota operacji. Kwota ujemna oznacza obciążenie rachunku
  (wydatek).

  W swoim rozwiązaniu nie używaj zmiennych (wprowadzanych za pomocą „var”)
  oraz konstrukcji „while” oraz „foreach”.

  Ćwiczenie 1: Napisz funkcję obliczającą sumaryczną wysokość wpływów i wydatków
  dla każdego z miesięcy

  Ćwiczenie 2. Napisz funkcję, która dla każdego dnia, którego data znajduje się
  w danych oblicza „balans konta”. Rozumiemy przez to wysokość sumy na koncie po
  uwzględnieniu operacji, które tego dnia zostały „zaksięgowane”. Załóż,
  że początkowy stan konta to 2500 zł.

  Ćwiczenie 3. Napisz funkcję znajdującą miesiąc(e), w którym balans wpływów
  i obciążeń rachunku był najkorzystniejszy tzn. suma wpływów pomniejszona
  o sumę obciążeń była maksymalna.

*/
package bank

object Main {

  type Balans = (Double, Double) //obciążenie, wplywy
  type Operacja = (String, Double) //data, kwota

  case class BalansKonta(obciążenia: Double, wpływy: Double)
  
  def count_add(x: List[(String, Double)]): Map[Int, BalansKonta] = {
    val operacja1 = x.groupBy(p => p._1.slice(5,7).toInt)
    val operacja2 = operacja1.mapValues[BalansKonta](p => obliczanieBalansu(p))
    operacja2
  } 

  def obliczanieBalansu(l: List[Operacja]): BalansKonta = {
    l.foldLeft(BalansKonta(0d, 0d))((a: BalansKonta, e: Operacja) =>
      if (e._2 > 0) {
        BalansKonta(a.obciążenia, a.wpływy + e._2)
      } else {
        BalansKonta(a.obciążenia + e._2, a.wpływy)
      })
  }
  
  def balansDzienny(l: List[Operacja]): BalansKonta = {
    l.foldLeft(BalansKonta(0d, 2500d))((a: BalansKonta, e: Operacja) =>
      if (e._2 > 0) {
        BalansKonta(a.obciążenia, a.wpływy + e._2)
      } else {
        BalansKonta(a.obciążenia + e._2, a.wpływy)
      })
  }
  
  def max(l: List[Operacja]): (Int, Double) = {
    val x = count_add(l)
    val z = x.mapValues { x => x.obciążenia + x.wpływy }
    z.maxBy(_._2)
  }
  
  def dayCount(l: List[Operacja]): List[(String, Double)] = {
    val start = 2500
    val operacja2 = l.groupBy { x => x._1.slice(5, 10) }
    val operacja3 = operacja2.mapValues[BalansKonta](p => balansDzienny(p))
    val operacja4 = operacja3.mapValues[Double](p => p.wpływy + p.obciążenia)
//    val operacja4 = operacja3.toList.foldLeft(Double, BalansKonta(0d, 0d))((a: Double, e: BalansKonta) => )
  //  operacja4
    operacja4.toList sortBy {_._1}
  }

/*
  def Balans(l: List[Operacja]): Balans = {
    l.foldLeft(0d, 0d)((a: Balans, e: Operacja) =>
      if (e._2 > 0) {
        (a._1, a._2 + e._2)
      } else {
        (a._1 + e._2, a._2)
      })
  }
*/

  def main(args: Array[String]): Unit = {
    //println(dane.groupBy(_._1.slice(5, 7)))
    //println(count_add(dane))
    //println(max(dane))
    println(dayCount(dane))
//    println(obliczanieBalansu(dane))
  }
}
