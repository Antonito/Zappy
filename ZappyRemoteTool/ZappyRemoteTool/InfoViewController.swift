//
//  InfoViewController.swift
//  ZappyRemoteTool
//
//  Created by Antoine Baché on 02/07/2017.
//  Copyright © 2017 Antoine Baché. All rights reserved.
//

import UIKit

class InfoViewController: UIViewController {
    
    @IBAction func decFreqAction(_ sender: Any) {
        print("Decreasing server's frequency")
        _ = NetworkManager.sharedInstance.send(msg: "dec")
    }
    
    @IBAction func incFreqAction(_ sender: Any) {
        print("Increasing server's frequency")
        _ = NetworkManager.sharedInstance.send(msg: "inc")

    }
    
    @IBOutlet weak var broadcastDistance: UITextField!
    @IBOutlet weak var broadcastMessage: UITextField!
    
    @IBAction func broadcastAction(_ sender: Any) {
        if broadcastMessage.text != nil && broadcastDistance.text != nil {
            let msg = broadcastDistance.text! + broadcastMessage.text!;
            print("Broadcasting to client: " + msg)
            _ = NetworkManager.sharedInstance.send(msg: "broadcast " + msg)
            broadcastMessage.text = ""
            broadcastDistance.text = ""
        }
    }
    
    @IBAction func resetAction(_ sender: Any) {
        print("Resetting server")
        _ = NetworkManager.sharedInstance.send(msg: "reset")
        NetworkManager.sharedInstance.disconnect()
        let storyBoard: UIStoryboard = UIStoryboard(name: "Main", bundle: nil)
        let newViewController = storyBoard.instantiateViewController(withIdentifier: "MainMenu") as! ViewController
        self.present(newViewController, animated: true, completion: nil)

    }
    
    @IBAction func stopAction(_ sender: Any) {
        print("Stopping server")
        _ = NetworkManager.sharedInstance.send(msg: "stop")
    }

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
