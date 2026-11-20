typedef struct {
    char* digits;
    int size;
    long long target;
    char expression[21];
    char** answers;
    int count;
    int capacity;
}
OperatorContext;
void searchOperators(OperatorContext* context, int position, int length, long long total, long long previous) {
    if (position == context->size) {
        if (total == context->target) {
            if (context->count == context->capacity) {
                context->capacity *= 2;
                context->answers = realloc(context->answers, context->capacity * sizeof(char*));
            }
            char* answer = malloc(length + 1);
            memcpy(answer, context->expression, length);
            answer[length] = 0;
            context->answers[context->count++] = answer;
        }
        return;
    }
    long long value = 0;
    for (int end = position; end < context->size; end++) {
        if (end > position && context->digits[position] == '0') break;
        value = value * 10 + context->digits[end] - '0';
        int width = end - position + 1;
        if (position == 0) {
            memcpy(context->expression, context->digits + position, width);
            searchOperators(context, end + 1, width, value, value);
        }
        else {
            memcpy(context->expression + length + 1, context->digits + position, width);
            context->expression[length] = '+';
            searchOperators(context, end + 1, length + width + 1, total + value, value);
            context->expression[length] = '-';
            searchOperators(context, end + 1, length + width + 1, total - value, -value);
            context->expression[length] = '*';
            searchOperators(context, end + 1, length + width + 1, total - previous + previous * value, previous * value);
        }
    }
}
char** addOperators(char* num, int target, int* returnSize) {
    OperatorContext context = {
        0
    };
    context.digits = num;
    context.size = strlen(num);
    context.target = target;
    context.capacity = 16;
    context.answers = malloc(context.capacity * sizeof(char*));
    searchOperators(&context, 0, 0, 0, 0);
    *returnSize = context.count;
    return context.answers;
}
