#!/usr/bin/python3

def generate(word):
    """ Generate any permutations of the word """
    if len(word) <= 1:
        return (word,)

    s = word[:-2]
    results = generate(s)

    return results


if __name__ == '__main__':
    word = input('Enter a word: ')

    print('Word is ' + word)

    for item in generate(word):
        #pass
        print(item)
