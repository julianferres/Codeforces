fun main(){
    val t = readLine()!!.toInt()
    var pos = mutableMapOf<Int, Int>();

    var l = 0; var r = 0;
    for(i in 0 until t){
        var line = readLine()!!.split(" ")
        val type = line[0]
        val id = line[1].toInt()

        if(type == "L"){
            pos.put(id, l);
            l--
        }
        else if(type == "R"){
            r++
            pos.put(id, r);
        }
        else { // Query de tipo "?"
            var aux = pos.get(id)!!
            println(minOf(aux - (l + 1), r - aux))

        }
    }
}

/*
 * l = 0 
 * r = 0 
 * 
 * 
 * 
 * 
 */