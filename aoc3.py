import regex as re
import sys

# Search for match group in string, mul(*,*),
# and return a list of strings, which are all the mul(*,*) instances

def find_mul(string):
    return re.findall(r'mul\((\d+),(\d+)\)', string)

# Calculate the sum of all the mul(*,*) instances
def find_sum(string):
    return sum([int(x)*int(y) for x,y in find_mul(string)])

# Search the input of the script. It could be a string,
# or a file read as a string.
# The script should be called:
# python3 aoc3.py <input>

def main():
    if len(sys.argv) == 2:
        input = sys.argv[1]
        if input[-4:] == '.txt':
            with open(input, 'r') as f:
                input = f.read()
        print("The mul(*,*) instances are:", find_mul(input))
        print(f"The sum of all the mul(*,*) instances is: {find_sum(input)}")
    else:
        print("Usage: python3 aoc3.py <input>")

if __name__ == '__main__':
    main()


