fun ok(a: List<Int>, mid: Int, m: Int, k: Int): Boolean {
    if(mid == a.size) return true
    var boxesNeeded = 1
    var actBoxSize = 0
    for(i in mid until a.size){
        if(a[i] + actBoxSize <= k){
            actBoxSize += a[i]
        } else {
            boxesNeeded++
            actBoxSize = a[i]
        }
    }
    // println("mid: ${mid}, boxesNeeded: ${boxesNeeded}")

    return boxesNeeded <= m
}

fun main(){
    var (n, m, k) = readLine()!!.split(" ").map { it.toInt() }
    var a = readLine()!!.split(" ").map { it.toInt() }

    var l = 0
    var r = n
    var ans = r

    while(l <= r){
        val mid = (l + r)/2
        if(ok(a, mid, m, k)){
            r = mid - 1
            ans = mid
        } else {
            l = mid + 1
        }
    }

    println(n - ans)    
}