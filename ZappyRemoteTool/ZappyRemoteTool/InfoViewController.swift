//
//  InfoViewController.swift
//  ZappyRemoteTool
//
//  Created by Antoine Baché on 02/07/2017.
//  Copyright © 2017 Antoine Baché. All rights reserved.
//

import UIKit

class InfoViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        let tap: UITapGestureRecognizer = UITapGestureRecognizer(target: self, action: #selector(UIInputViewController.dismissKeyboard))
        view.addGestureRecognizer(tap)
        
        print("Loaded InfoViewController")
        print("Getting infos about server")

        let ret = NetworkManager.sharedInstance.send(msg: "info")
        switch ret {
        case .success:
            break;
        case .failure(let err):
            print(err)
            return ;
            break;
        }
        let data = NetworkManager.sharedInstance.read(1024 * 10)
        if let d = data {
            if let str = NSString(bytes: d, length: d.count, encoding: String.Encoding.utf8.rawValue) {
                print(str)
            }
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func dismissKeyboard() {
        view.endEditing(true)
    }
    
    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
