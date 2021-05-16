using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace ALG_lab7_8
{
    class Program
    {
        public static string[] Routes =  
        {
            "Київ",
            "Житомир",
            "Біла церква",
            "Прилуки",
            "Новоград-Волинський",
            "Бердичів",
            "Шепетівка",
            "Умань",
            "Черкаси",
            "Полтава",
            "Суми",
            "Миргород",
            "Рівне",
            "Вінниця",
            "Кременчук",
            "Харків",
            "Луцьк",
            "Хмельницький",
            "Тернопіль",
        };

        public const int n = 19; // Вершини матриці
        public static bool[] Peaks = new bool[n]; // Масив вершин
        public static List<int> List = new List<int>(); // Стек
        public static Queue<int> Queue = new Queue<int>(); // Черга
        public static List<int> Distance = new List<int>(); // Відстань між містами

        public static byte[,] MatrixAdjacency = // Матриця суміжностей
        {
            {0, 135, 78, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            {0, 0, 0, 0, 80, 38, 115, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            {0, 0, 0, 0, 0, 0, 0, 115, 146, 181, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 175, 109, 0, 0, 0, 0, 0, 0, 0 },
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0 },
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 73, 0, 0, 0, 0, 0 },
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 105, 0, 0, 0, 0 },
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 130, 0, 0, 0 },
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 68, 0, 0 },
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 110, 0 },
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 104 },
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        };

        public static void DFS(int f, int sum = 0)  //DFS
        {
            if (!Peaks[f])
            {
                List.Add(f);
                Peaks[f] = true;
                for (int i = 0; i < n; i++)      //прохід по всім вершинам графу
                {
                    if (MatrixAdjacency[f, i] != 0) //якщо є зв'язок записуємо іеформацію
                    {
                        sum += MatrixAdjacency[f, i];    //додавання вершини в стек
                        DFS(i, sum);
                        foreach (int city in List)
                        {
                            Write($"{Routes[city]} -> ");
                        }
                        Write($"{sum}\n");
                        sum -= MatrixAdjacency[f, i];     //видаляємо зі стека верхні вершини 
                        List.RemoveAt(List.Count - 1);
                    }
                }
            }
        }

        public static void BFS(int f) //BFS
        {
            string start = Routes[f];
            Peaks[f] = true;
            Queue.Enqueue(f);
            Distance.Add(0);
            while (Queue.Count != 0)    //додаємо до черги вершини 
            {
                f = Queue.Dequeue();
                for (int i = 0; i < n; i++)   //обхід всіх вершин графа
                {
                    if (MatrixAdjacency[f, i] != 0 && !Peaks[i]) //якщо є зв'язок або вже вершина , записуємо дані
                    {
                        Peaks[i] = true;
                        Queue.Enqueue(i);
                        Distance.Add(Distance[f] + MatrixAdjacency[f, i]);
                        WriteLine(start + " -> " + Routes[i] + ": " + Distance[i]);
                    }
                }
            }
        }
        static void Main(string[] args)
        {
            OutputEncoding = System.Text.Encoding.Unicode;
            InputEncoding = System.Text.Encoding.Unicode;


            for (int i = 0; i < n; i++)
            {
                Peaks[i] = false;
            }

            WriteLine("\nПошук в глибину(DFS): ");                  
            DFS(0);

            for (int i = 0; i < n; i++)
            {
                Peaks[i] = false;
            }

            WriteLine("\nПошук в ширину(BFS): ");                
            BFS(0);
        }





    }
}
