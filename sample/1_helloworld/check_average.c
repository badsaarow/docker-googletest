int check_average(int idx) {
    int i, total;
    total = 0;

    for (i = 0; i < idx; i++)
    {
        total += i;
    }

    if (total != 45)
        return 0;
    else
        return 1;
    
}