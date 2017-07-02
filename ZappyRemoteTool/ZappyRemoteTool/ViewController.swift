//
//  ViewController.swift
//  ZappyRemoteTool
//
//  Created by Antoine Baché on 02/07/2017.
//  Copyright © 2017 Antoine Baché. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    // Home informations
    @IBOutlet weak var zappyServer: UITextField!
    @IBOutlet weak var zappyPort: UITextField!
    @IBOutlet weak var zappyPassword: UITextField!

    // Connects to the zappy server
    @IBAction func zappyConnection(_ sender: Any) {
        if zappyServer.text != nil && zappyPort.text != nil && zappyPassword.text != nil {
            print("Server and port OK")
            // TODO: rm
            //zappyServer.text = "10.10.253.98"
            //zappyPort.text = "4243"
            if NetworkManager.sharedInstance.connect(address: zappyServer.text!, port: UInt16(zappyPort.text!)!) {
                print("Connected to server.")
                let password = "aSuperWeakAndUnsafePassword" // zappyPassword.text!
                let ret = NetworkManager.sharedInstance.authenticate(passwd: password)
                switch ret {
                case .success:
                    print("Authenticated !")
                    let storyBoard: UIStoryboard = UIStoryboard(name: "Main", bundle: nil)
                    let newViewController = storyBoard.instantiateViewController(withIdentifier: "InfoViewController") as! InfoViewController
                    self.present(newViewController, animated: true, completion: nil)
                case .failure(let err):
                    print(err)
                }
            }
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.

        let tap: UITapGestureRecognizer = UITapGestureRecognizer(target: self, action: #selector(UIInputViewController.dismissKeyboard))
        view.addGestureRecognizer(tap)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    func dismissKeyboard() {
        view.endEditing(true)
    }

}

