  val l = List(List(1,2,3,4), List(4,5,6,7))
  val z = l.flatten.foldLeft(List[Int]()){(a, b) => if(b % 2 == 0) b::a else a}
  println(z)
 }
