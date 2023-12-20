// node.h
#pragma once

class Node {
public:
    Node(HoaDon* data) : dataHoaDon(data), next(nullptr) {}
    Node(NhanVien* data) : dataNhanVien(data), next(nullptr) {}
    Node(KhachHang* data) : dataKhachHang(data), next(nullptr) {}
    Node(SanPham* data) : dataSanPham(data), next(nullptr) {}

    HoaDon* GetData() const {
        return data;
    }

    Node* GetNext() const {
        return next;
    }

    void SetNext(Node* newNext) {
        next = newNext;
    }

private:
    HoaDon* data;
    Node* next;
};
