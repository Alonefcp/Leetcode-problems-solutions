
int searchInsert(vector<int>& nums, int target) 
{

    int inicio = 0;
    int fin = nums.size() - 1;

    while (inicio <= fin)
    {
        int medio = inicio + (fin - inicio) / 2;

        if (nums[medio] == target)
        {
            return medio;
        }
        else if (nums[medio] < target)
        {
            inicio = medio + 1;
        }
        else 
        {
            fin = medio - 1;
        }
    }

    return inicio;

}