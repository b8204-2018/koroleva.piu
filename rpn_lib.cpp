//
// Created by polina on 14.06.19.
//

#include "rpn_lib.h"

Reader::Reader(ifstream &f, string &filename) {
    this->f = &f;
    this->filename = filename;
}

Reader *Reader::create(string filename) {
    ifstream f(filename);
    if (!f.is_open()) {
        return nullptr;
    } else {
        return new Reader(f, filename);
    }
}

string Reader::readLine() {
    string s;
    f->open(filename, ios_base::in);
    if (f->is_open()) {
        *f >> s;
        f->close();
    }
    return s;
}

Reader::~Reader() {
    delete f;
}


Writer::Writer(ofstream &f, string &filename) {
    this->filename = filename;
    this->f = &f;
}

Writer *Writer::create(string filename) {
    ofstream f(filename);
    if (!f.is_open()) {
        return nullptr;
    } else {
        return new Writer(f, filename);
    }
}

void Writer::write(string s) {
    *f << s;
}

Writer::~Writer() {
    delete f;
}
