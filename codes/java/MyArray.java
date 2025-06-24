
public class MyArray {

    private int[] data;
    private int size_;
    private int capatity_;

    private void resize(int new_capatity) {
        int[] new_data = new int[new_capatity];
        for (int i = 0; i < this.size_; ++i) {
            new_data[i] = data[i];
        }
        this.data = new_data;
        this.capatity_ = new_capatity;
    }

    public MyArray() {
        this.capatity_ = 16;
        this.size_ = 0;
        this.data = new int[16];
    }

    public int size() {
        return this.size_;
    }

    public boolean empty() {
        return this.size_ == 0;
    }

    public int get(int pos) {
        return this.data[pos];
    }

    public int at(int pos) {
        return this.data[pos];
    }

    public void push(int x) {
        if (this.size_ == this.capatity_) {
            resize(2 * this.capatity_);
        }
        this.data[this.size_] = x;
        this.size_++;
    }

    public void insert(int pos, int x) {
        if (this.size_ == this.capatity_) {
            resize(2 * this.capatity_);
        }
        for (int i = this.size_; i > pos; i++) {
            this.data[i] = this.data[i - 1];
        }
        this.data[pos] = x;
        this.size_++;
    }

    public void prepush(int x) {
        insert(0, x);
    }

    public int pop() {
        int val = this.data[this.size_ - 1];
        this.size_--;
        if (this.size_ * 4 <= this.capatity_ && this.capatity_ > 16) {
            resize(this.capatity_ / 2);
        }
        return val;
    }

    public void remove_at(int pos) {
        for (int i = pos; i < this.size_ - 1; i++) {
            this.data[i] = this.data[i + 1];
        }
        this.size_--;
        if (this.size_ * 4 <= this.capatity_ && this.capatity_ > 16) {
            resize(this.capatity_ / 2);
        }
    }

    public void remove(int val) {
        int cnt = 0;
        for (int i = 0; i < this.size_ - cnt; i++) {
            if (this.data[i] == val) {
                ++cnt;
            }
            if (i + cnt < this.size_) {
                this.data[i] = this.data[i + cnt];
            }
        }
        this.size_ -= cnt;
        if (this.size_ * 4 <= this.capatity_ && this.capatity_ > 16) {
            resize(this.capatity_ / 2);
        }
    }
}
