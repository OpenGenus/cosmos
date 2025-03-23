//Part of Cosmos by OpenGenus Foundation
function search(txt,pat){

    var N = txt.length;
    var M = pat.length;   

    //Iterate pat[]
    for(var i=0;i<N-M+1;i++){

        //For current index i, check for pattern match
        for(var j=0;j<M;j++){
        
            if(txt[i+j] != pat[j]){
                //console.log("not working");
                break;
            }
        }
        if(j == M) //if pat[0...M-1] = txt[i, i+1, ...i+M-1]
        console.log("Pattern found at index " + i);
    }
}