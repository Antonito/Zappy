//
//  NetworkManager.swift
//  ZappyRemoteTool
//
//  Created by Antoine Baché on 02/07/2017.
//  Copyright © 2017 Antoine Baché. All rights reserved.
//

import Foundation
import SwiftSocket

// Singleton Network Manager
class NetworkManager {
    static let sharedInstance = NetworkManager()
    
    var client: TCPClient?
    
    func connect(address: String, port: UInt16) -> Bool {
        var ret = true
        print("Connecting to " + address + ":" + String(port))
        client = TCPClient(address: address, port: Int32(port))
        
        switch client!.connect(timeout: 10) {
        case .success:
            print("Connection successful !")
        case .failure(let error):
            print(error)
            ret = false
        }
        return ret
    }
    
    func disconnected() {
        client!.close()
    }
    
    func read(_ len: Int) -> [Byte]? {
        return client!.read(len)
    }
    
    func send(msg: String) -> Result {
        return client!.send(string: msg + "\n")
    }
    
    func authenticate(passwd: String) -> Result {
        let ret = self.send(msg: passwd)
        
        switch ret {
        case .success:
            let data = client?.read(1024 * 10)
            if let d = data {
                if let str = NSString(bytes: d, length: d.count, encoding: String.Encoding.utf8.rawValue) {
                    print(str)
                }
            }
            break
        case .failure(let err):
            print(err)
            break
        default:
            break
        }
        return ret
    }
    
    private init(){}
}
