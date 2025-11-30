acquire(){
    while (!available)
    ;
    available = false;
}

release(){
    available = ture;
}