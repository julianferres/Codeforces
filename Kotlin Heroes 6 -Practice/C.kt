fun main(){
    var n = readLine()!!.toInt()
    var a = readLine()!!.toString()
    var ans = 0
    var i = 0;
    while(i < n){
        if(a[i] == 'x'){
            var j = i;
            while(j+1 < n && a[j+1] == a[i]){
                j++
            }
            ans += maxOf(0, (j - i + 1) - 2)
            i = j+1
        } else{
            i++
        }
    }

    println(ans)
}   