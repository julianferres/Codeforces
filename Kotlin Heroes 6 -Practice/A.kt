fun main(args: Array<String>) {
    var n = readLine()!!.toInt()
    val a = readLine()!!.split(' ').map { it.toInt() }

    val ans = BooleanArray(n){ true }

    for(i in 0 until n){
        for(j in i+1 until n){
            if(a[i] == a[j]) ans[i] = false
        }
    }

    println("${ans.count {it}}")

    for(i in 0 until n){
        if(ans[i]){
            print("${a[i]} ")
        }
    }
}   