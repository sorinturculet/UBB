using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab1
{
    public class Words
    {
        public Words() { }
        // Reads the file content and returns a dictionary of word frequencies.
        public SortedDictionary<string,int> Process(string filename)
        {
            string data = this.Read(filename);
            if (data == null)
                return null;
            else
            {
                return WordFrequency(data);
            }
        }
        // Reads the file content. Returns null if the file cannot be read
        public string Read(string filename)
        {
            try
            {
                string data = File.ReadAllText(filename);
                return data;
            }
            catch
            {
                
                return null;
            }
        }
        // Checks if the character is a whitespace character (space, tab, or newline).
        public bool isWhiteSpace(char ch)
        {
            return ch == ' ' || ch == '\t' || ch == '\n';
        }
        // Returns a SortedDictionary with each word as the key and its frequency as the value.
        public SortedDictionary<string,int> WordFrequency(string data)
        {
            SortedDictionary<string,int> dict = new SortedDictionary<string,int>();
            int i = 0;
            int counter = 0;
            bool inWord = false;
            string word = "";
            while(i < data.Length)
            {
                
                if (isWhiteSpace(data[i]))
                {// We reached a whitespace character. This is the end of the word
                    if (inWord)
                    {
                        inWord = false;
                        if (dict.ContainsKey(word)) // The word has already been found before; increment its count.

                            dict[word]++;
                        else
                            dict[word] = 1; // First appearance of the word; initialize with 1.
                        word = "";
                        counter++;

                    }

                }
                else
                {//Inside a word; add characters to it.
                    word += data[i];
                    if (inWord == false)
                    {
                        inWord = true;
                    }
                }
 
                i++;

            }
            if (inWord)
            {
                counter++; // Final word; add it to the dictionary if it exists.
                if (dict.ContainsKey(word)) // The word has already been found before; increment its count.
                    dict[word]++;
                else
                    dict[word] = 1; // First appearance of the word; initialize with 1.

            }

            return dict;
        }
        public int Count(string data)
        {
            int i = 0;
            int counter = 0;
            bool inWord = false;
            string word = "";
            while (i < data.Length)
            {

                if (isWhiteSpace(data[i]))
                {
                    if (inWord)
                    {
                        inWord = false;
                        word = "";
                        counter++;

                    }

                }
                else
                {
                    word += data[i];
                    if (inWord == false)
                    {
                        inWord = true;
                    }
                }

                i++;

            }
            if (inWord)
            {
                counter++; //final word
            }
            return counter;
        }

    }
    internal class Program
    {
        static void Main(string[] args)
        {
            // Invalid number of arguments.
            if (args.Length != 1)
                Console.WriteLine("Argument Error");
            else
            {   //Constructing the current file path
                string filePath = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, args[0]);
                Words words = new Words();
                // Using a SortedDictionary to keep the words sorted for easier output.
                SortedDictionary<string,int> frequencies = words.Process(filePath);
                if (frequencies == null)
                {
                    Console.WriteLine("File Error");
                }
                else{
                    foreach (var pair in frequencies)
                    {
                        Console.WriteLine(pair.Key+": "+pair.Value);
                    }
                }
            }
        }
    }
}
