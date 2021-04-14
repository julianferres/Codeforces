fun main(){
    val n = readLine()!!.toInt()
    var a = arrayListOf<String>();

    for(line in 0 until n){
        a.add(readLine()!!)
    }
    a.sortWith(compareBy {it.length})
    var possible = true

    for(i in 1 until n){
        possible = possible && (a[i-1] in a[i])
    }

    if(!possible){
        println("NO")
    } else {
        println("YES")
        for(ans in a) println(ans)
    }

}