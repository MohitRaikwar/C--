
// bool heap_decrease_key(vector<int> &hT, int i, int key)
// {
//     if (hT[i] < key)
//         return false;
//     else
//     {
//         hT[i] = key;
//         while (i > 0 && hT[i / 2] > hT[i])
//             swap(&hT[i / 2], &hT[i]);
//         return true;
//     }
// }