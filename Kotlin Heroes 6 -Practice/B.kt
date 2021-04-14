fun main(){
    var t = readLine()!!.toInt()
    for(testcase in 0 until t){
        var (n, a, b) = readLine()!!.split(' ').map { it.toLong() }
        b = minOf(b, 2*a)
        var ans = 0L
        if(n % 2 == 1L){
            ans += a
        }
        // println("${a} ${b} ${n/2}")
        ans += b * (n/2)

        println(ans)
    }

}