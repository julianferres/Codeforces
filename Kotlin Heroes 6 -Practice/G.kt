data class Edge(val from: Int, val to: Int, val cost: Long)

class DSU(val n: Int){
    var par: MutableList<Int> = MutableList<Int>(n){ it }
    var sz: MutableList<Int> = MutableList<Int>(n){ 1 }

    fun find(x: Int): Int {
        if(par[x] != x) par[x] = find(par[x])
        return par[x]
    }
    
    fun join(ii: Int, jj: Int): Boolean{
        var i=find(ii); var j=find(jj);
        if(i == j) return false; 
        if(sz[i] < sz[j]){
            run { val temp = i; i = j; j = temp }
        }
        sz[i] += sz[j];
        par[j] = i;
        return true            
    }
}


fun main() {
    var (n, m) = readLine()!!.split(" ").map { it.toInt() }
    var a = readLine()!!.split(" ").map { it.toLong() }

    var mindex = a.indexOf(a.minBy{ it })

    var edges = mutableListOf<Edge>()


    repeat(m){
        var line = readLine()!!.split(" ")
        var from = line[0].toInt()
        var to = line[1].toInt()
        var cost = line[2].toLong()

        edges.add(Edge(from-1, to-1, cost))
    }

    for (i in 0 until n){
        edges.add(Edge(i, mindex, a[mindex] + a[i]))
    }

    edges.sortWith(compareBy {it.cost})
    var dsu = DSU(n)
    var ans = 0L

    for(edge in edges){
        if(dsu.find(edge.from) == dsu.find(edge.to)) continue
        else{
            ans += edge.cost
            dsu.join(edge.from, edge.to)
        }
    }

    println(ans)
}
