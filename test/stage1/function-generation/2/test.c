int hoge(void);
int huga(void);

int main() {
    int res;
    res = hoge();
    if (res != 0) {
        return 1;
    }
    res = huga();
    if (res != 0) {
        return 1;
    }
    return 0;
}
