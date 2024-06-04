

def find_sequences(words):
    start_letter_dict = {}
    for word in words:
        first_letter = word[0]
        if first_letter not in start_letter_dict:
            start_letter_dict[first_letter] = []
        start_letter_dict[first_letter].append(word)
    for key in start_letter_dict:
        start_letter_dict[key].sort()

    def movingOnNames(current_word, sequence, used_words):
        last_letter = current_word[-1]
        candidates = start_letter_dict.get(last_letter, [])
        max_sequence = sequence
        for candidate in candidates:
            if candidate not in used_words:
                new_sequence = sequence + [candidate]
                used_words.add(candidate)
                result_sequence = movingOnNames(candidate, new_sequence, used_words)
                if (len(result_sequence) > len(max_sequence) or
                        (len(result_sequence) == len(max_sequence) and result_sequence < max_sequence)):
                    max_sequence = result_sequence
                used_words.remove(candidate)
        return max_sequence
    
    best_sequence = []
    for word in words:
        current_sequence = movingOnNames(word, [word], {word})
        if len(current_sequence) > len(best_sequence) or (len(current_sequence) == len(best_sequence) and current_sequence < best_sequence):
            best_sequence = current_sequence
    return best_sequence
    

user_input = input()
words = user_input.split(', ')
result = find_sequences(words)
for word in result:
    print(word, end=', ') if word != result[-1] else print(word)

